# Given a function that generates perfectly random numbers between 1 and k
# (inclusive), where k is an input, write a function that shuffles a deck
# of cards represented as an array using only swaps.
#
# It should run in O(N) time.
#
# Hint: Make sure each one of the 52! permutations of the deck is equally likely.

from random import randint


def shuffle(array):
    for i in range(len(array)):
        selected = randint(i, len(array) - 1)
        array[selected], array[i] = array[i], array[selected]


array = [i for i in range(52)]

counts = [0] * 52
for i in range(100000):
    shuffle(array)
    for j, num in enumerate(array):
        counts[j] += num

print(counts)
