# The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
# For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
# You may also use a list or array to represent a set.


def power_set(input_set):
    transformed = list(input_set)
    result = []

    def generate_index(index, added):
        if index == len(input_set):
            result.append(set(added))
            return

        generate_index(index + 1, added)
        added.append(transformed[index])
        generate_index(index + 1, added)
        added.pop()

    generate_index(0, [])
    return result

test1 = set([1, 2, 3])

print(power_set(test1))
