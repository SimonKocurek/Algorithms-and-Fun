def partition_exists(multiset, index, current_sum, target_sum):
    if current_sum == target_sum:
        return True

    if index + 1 == len(multiset):
        return False

    new_index = index + 1
    return partition_exists(multiset, new_index, current_sum + multiset[index], target_sum) or \
        partition_exists(multiset, new_index, current_sum, target_sum)

def first_partition_exists(multiset, partition_sum):
    return partition_exists(multiset, 0, 0, partition_sum)

def same_sum_partition_possible(multiset):
    if len(multiset) <= 1:
        return False

    partition_sum = sum(multiset) / 2
    return first_partition_exists(multiset, partition_sum)

print(same_sum_partition_possible([15, 5, 20, 10, 35, 15, 10]))
print(same_sum_partition_possible([15, 5, 20, 10, 35]))
print(same_sum_partition_possible([15]))
print(same_sum_partition_possible([]))
print(same_sum_partition_possible([10, 10]))
print(same_sum_partition_possible([10, 9]))
