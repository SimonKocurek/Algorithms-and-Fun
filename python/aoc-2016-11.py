# --- Day 11: Radioisotope Thermoelectric Generators ---
# You come upon a column of four floors that have been entirely sealed off from the rest of the building except for a
# small dedicated lobby. There are some radiation warnings and a big sign which reads "Radioisotope Testing Facility".
#
# According to the project status board, this facility is currently being used to experiment with Radioisotope
# Thermoelectric Generators (RTGs, or simply "generators") that are designed to be paired with specially-constructed
# \microchips. Basically, an RTG is a highly radioactive rock that generates electricity through heat.
#
# The experimental RTGs have poor radiation containment, so they're dangerously radioactive. The chips are prototypes
# and don't have normal radiation shielding, but they do have the ability to generate an electromagnetic radiation
# shield when powered. Unfortunately, they can only be powered by their corresponding RTG. An RTG powering a microchip
# is still dangerous to other microchips.
#
# In other words, if a chip is ever left in the same area as another RTG, and it's not connected to its own RTG, the
# chip will be fried. Therefore, it is assumed that you will follow procedure and keep chips connected to their
# corresponding RTG when they're in the same room, and away from other RTGs otherwise.
#
# These microchips sound very interesting and useful to your current activities, and you'd like to try to retrieve them.
# The fourth floor of the facility has an assembling machine which can make a self-contained, shielded computer for you
# to take with you - that is, if you can bring it all of the RTGs and microchips.
#
# Within the radiation-shielded part of the facility (in which it's safe to have these pre-assembly RTGs), there is an
# elevator that can move between the four floors. Its capacity rating means it can carry at most yourself and two RTGs
# or microchips in any combination. (They're rigged to some heavy diagnostic equipment - the assembling machine will
# detach it for you.) As a security measure, the elevator will only function if it contains at least one RTG or
# microchip. The elevator always stops on each floor to recharge, and this takes long enough that the items within it
# and the items on that floor can irradiate each other. (You can prevent this if a Microchip and its Generator end up
# on the same floor in this way, as they can be connected while the elevator is recharging.)
#
# You make some notes of the locations of each component of interest (your puzzle input). Before you don a hazmat suit
# and start moving things around, you'd like to have an idea of what you need to do.
#
# When you enter the containment area, you and the elevator will start on the first floor.
#
# For example, suppose the isolated area has the following arrangement:
#
#     The first floor contains a hydrogen-compatible microchip and a lithium-compatible microchip.
#     The second floor contains a hydrogen generator.
#     The third floor contains a lithium generator.
#     The fourth floor contains nothing relevant.
#
# In your situation, what is the minimum number of steps required to bring all of the objects to the fourth floor?

from collections import namedtuple
from queue import Queue
from typing import Tuple, Iterable

Generators = Tuple[str, ...]
Chips = Tuple[str, ...]
Floors = Tuple['Floor', ...]
Movable = namedtuple('Movable', ['generators', 'chips'])

FLOORS = 4


class Floor:
    def __init__(self, id: int, generators: Generators, chips: Chips):
        self.id = id
        self.generators = tuple(sorted(generators))
        self.chips = tuple(sorted(chips))

    def get_movables(self) -> Iterable[Movable]:
        for generator in self.generators:
            yield Movable((generator,), tuple())

        for chip in self.chips:
            yield Movable(tuple(), (chip,))

        for generator in self.generators:
            for chip in self.chips:
                yield Movable((generator,), (chip,))

        for i in range(len(self.generators)):
            for j in range(i + 1, len(self.generators)):
                yield Movable((self.generators[i], self.generators[j]), tuple())

        for i in range(len(self.chips)):
            for j in range(i + 1, len(self.chips)):
                yield Movable(tuple(), (self.chips[i], self.chips[j]))

    def is_valid(self) -> bool:
        unsafe_generators = set(self.generators)
        unsafe_chips = set(self.chips)

        for chip in self.chips:
            if chip in unsafe_generators:
                unsafe_generators.remove(chip)
                unsafe_chips.remove(chip)

        return len(unsafe_generators) == 0 or len(unsafe_chips) == 0

    def is_highest(self) -> bool:
        return self.id + 1 == FLOORS

    def is_empty(self) -> bool:
        return len(self.generators) == 0 and len(self.chips) == 0

    def __eq__(self, other) -> bool:
        return (self.id, self.generators, self.chips) == (other.id, other.generators, other.chips)

    def __hash__(self) -> int:
        return self.id + hash(self.generators) + hash(self.chips)

    def __str__(self) -> str:
        return f'id={self.id} generators={self.generators} chips={self.chips}'

    def __repr__(self) -> str:
        return str(self)


class State:
    def __init__(self, elevator: int, floors: Floors):
        if floors is None:
            floors = tuple(Floor(i, tuple(), tuple()) for i in range(FLOORS))

        self.floors = tuple(floors)
        self.elevator = elevator

    def is_final(self) -> bool:
        for floor in self.floors:
            if not floor.is_highest() and not floor.is_empty():
                return False

        return True

    def floor_without_movables(self, movable: Movable) -> Floor:
        current_floor = self.floors[self.elevator]

        new_generators = tuple(
            generator for generator in current_floor.generators if generator not in movable.generators)
        new_chips = tuple(chip for chip in current_floor.chips if chip not in movable.chips)

        return Floor(self.elevator, generators=new_generators, chips=new_chips)

    def floor_with_movables(self, id: int, movable: Movable) -> Floor:
        floor = self.floors[id]

        new_generators = floor.generators + movable.generators
        new_chips = floor.chips + movable.chips

        return Floor(id, generators=new_generators, chips=new_chips)

    def move_elevator(self, elevator: int, movable: Movable, new_current_floor: Floor) -> Iterable['State']:
        new_moved_floor = self.floor_with_movables(elevator, movable)

        if not new_moved_floor.is_valid():
            return

        if elevator > self.elevator:
            new_floors = self.floors[:self.elevator] + (new_current_floor, new_moved_floor) + self.floors[elevator + 1:]
            yield State(elevator, new_floors)
        else:
            new_floors = self.floors[:elevator] + (new_moved_floor, new_current_floor) + self.floors[self.elevator + 1:]
            yield State(elevator, new_floors)

    def get_possible_states(self) -> Iterable['State']:
        current_floor = self.floors[self.elevator]

        for movables in current_floor.get_movables():
            new_current_floor = self.floor_without_movables(movables)

            if not new_current_floor.is_valid():
                continue

            if self.elevator > 0:
                yield from self.move_elevator(self.elevator - 1, movables, new_current_floor)

            if self.elevator + 1 < FLOORS:
                yield from self.move_elevator(self.elevator + 1, movables, new_current_floor)

    def __eq__(self, other) -> bool:
        return (self.elevator, self.floors) == (other.elevator, other.floors)
        # return str(self) == str(other)

    def __hash__(self) -> int:
        return self.elevator + hash(self.floors)
        # return self.elevator

    def __str__(self) -> str:
        return f'elevator={self.elevator} floors={self.floors}'


class Parser:
    @staticmethod
    def parse_line(id: int) -> Floor:
        line = input()

        if 'nothing relevant' in line:
            return Floor(id, tuple(), tuple())

        chips = []
        generators = []

        trimmed_line = line[line.find('a ') + 2:]
        for part in trimmed_line.split('a '):
            item = part.split()
            name = item[0][:2]

            if 'generator' in item[1]:
                generators.append(name)
            else:
                chips.append(name)

        return Floor(id, generators=tuple(generators), chips=tuple(chips))

    @staticmethod
    def parse_input() -> State:
        floors = (Parser.parse_line(i) for i in range(FLOORS))
        return State(0, tuple(floors))


def least_moves(initial_state: State) -> int:
    if initial_state.is_final():
        return 0

    seen = set()
    next = Queue()

    next.put((initial_state, 0))
    seen.add(initial_state)

    while not next.empty():
        current_state, moves = next.get()
        next_moves = moves + 1

        for next_state in current_state.get_possible_states():
            if next_state.is_final():
                return next_moves

            if next_state in seen:
                continue

            seen.add(next_state)
            next.put((next_state, next_moves))

            if len(seen) > 4**11:
                print('debilina')
                return

    raise Exception('Getting to final state is not possible')


def main():
    state = Parser.parse_input()
    print(least_moves(state))


main()
