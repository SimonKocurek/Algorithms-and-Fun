import java.util.*;

class Pair {

    private final int generator;
    private final int chip;

    Pair(int generator, int chip) {
        this.generator = generator;
        this.chip = chip;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return generator == pair.generator &&
                chip == pair.chip;
    }

    @Override
    public int hashCode() {
        return Objects.hash(generator, chip);
    }

}

class State {

    private final int elevator;
    private final Map<Pair, Integer> pairs;

    State(List<Integer> state) {
        this.elevator = state.get(0);
        this.pairs = new HashMap<>();
        for (int i = 1; i < state.size(); i += 2) {
            var pair = new Pair(state.get(i), state.get(i + 1));
            pairs.merge(pair, 1, Integer::sum);
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        State state = (State) o;
        return elevator == state.elevator &&
                Objects.equals(pairs, state.pairs);
    }

    @Override
    public int hashCode() {
        return Objects.hash(elevator, pairs);
    }

}

public class aoc_2016_11_bonus {

    public static void main(String[] args) {
        // Encoded due to performance reasons:
        // state[0] - elevator
        // state[1,2] - thulium generator, thulium microchip
        // state[3,4] - plutonium generator, plutionium microchip
        // ....
        var state = new ArrayList<>(List.of(0, 0, 0, 0, 1, 0, 1, 2, 2, 2, 2, 0, 0, 0, 0)); // wrapped to make it mutable

        var seen = new HashSet<State>();
        seen.add(new State(state));

        Queue<List<Integer>> states = new ArrayDeque<>();
        Queue<Integer> distances = new ArrayDeque<>();
        states.offer(state);
        distances.offer(0);

        while (!states.isEmpty()) {
            var currentState = states.poll();
            var currentDistance = distances.poll();

            for (var nextState : getNextStates(currentState)) {
                var stateWithProperEquals = new State(nextState);
                if (seen.contains(stateWithProperEquals)) {
                    continue;
                }

                seen.add(stateWithProperEquals);
                states.offer(nextState);
                distances.offer(currentDistance + 1);

                if (isWinningState(nextState)) {
                    System.out.println(currentDistance + 1);
                    return;
                }
            }
        }
    }

    private static List<List<Integer>> getNextStates(List<Integer> state) {
        List<List<Integer>> result = new ArrayList<>();

        // Don't return to empty floors
        if (state.get(0) > 0) {
            GetMovedStates(state, result, -1);
        }

        if (state.get(0) < 3) {
            GetMovedStates(state, result, 1);
        }

        return result;
    }

    private static void GetMovedStates(List<Integer> state, List<List<Integer>> result, int elevatorMove) {
        var elevatorPosition = state.get(0);

        // Move elevator
        state.set(0, elevatorPosition + elevatorMove);

        for (int i = 1; i < state.size(); i++) {
            // On other floor
            if (!state.get(i).equals(elevatorPosition)) {
                continue;
            }

            state.set(i, state.get(i) + elevatorMove);

            if (!isValid(state)) {
                state.set(i, state.get(i) - elevatorMove);
                continue;
            }

            for (int j = i + 1; j < state.size(); j++) {
                // On other floor
                if (!state.get(j).equals(elevatorPosition)) {
                    continue;
                }

                state.set(j, state.get(j) + elevatorMove);
                if (isValid(state)) {
                    result.add(new ArrayList<>(state));
                }
                state.set(j, state.get(j) - elevatorMove);
            }

            // Don't go up with 1 piece
            if (elevatorMove < 0) {
                result.add(new ArrayList<>(state));
            }

            state.set(i, state.get(i) - elevatorMove);
        }

        // Move elevator
        state.set(0, elevatorPosition);
    }

    /**
     * @return Does not have microchips with incompatible generators on same floor
     */
    private static boolean isValid(List<Integer> state) {
        for (int i = 1; i < state.size(); i += 2) {
            // secured generator
            if (state.get(i).equals(state.get(i + 1))) {
                continue;
            }

            for (int j = i + 3; j < state.size(); j += 2) {
                // secured microchip
                if (state.get(j).equals(state.get(j - 1))) {
                    continue;
                }

                // unsecured generator on floor with unsecured chip
                if (state.get(j).equals(state.get(i))) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * @return Everything is on the 4th floor
     */
    private static boolean isWinningState(List<Integer> state) {
        for (var value : state) {
            if (value != 3) {
                return false;
            }
        }

        return true;
    }

}
