# Given a array of numbers representing the stock prices of a company
# in chronological order, write a function that calculates the maximum
# profit you could have made from buying and selling that stock once.
# You must buy before you can sell it.
#
# For example, given [9, 11, 8, 5, 7, 10], you should return 5, since
# you could buy the stock at 5 dollars and sell it at 10 dollars.
from sys import maxsize

def max_profit(stock):
    result = 0
    lowest = maxsize

    for num in stock:
        result = max(result, num - lowest)
        lowest = min(lowest, num)

    return result

print(max_profit([9, 11, 8, 5, 7, 10]))
print(max_profit([9, 11]))
