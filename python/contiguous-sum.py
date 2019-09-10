from typing import List

def largest_sum(arr: List[int]) -> int:
    result = 0
    
    got = 0
    for value in arr:
        if got + value > value:
            got += value
        else:
            got = value

        result = max(result, got)

    return result

def main() -> None:
    print(largest_sum([1, 1, 2, 3, 4]))
    print(largest_sum([]))
    print(largest_sum([-1]))
    print(largest_sum([9, 0, 1, -11, 12, -1, 2]))

if __name__ == "__main__":
    main()