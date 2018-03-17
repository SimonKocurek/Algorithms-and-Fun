/*
Given an array of integers and a number k, where 1 <= k <= length of the array, 
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and 
you do not need to store the results. You can simply print them out as you compute them.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> running_max(vector<int> &numbers, int k)
{
    vector<int> result;

    if (numbers.empty())
    {
        return result;
    }

    list<int> sorted;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (sorted.front() == i - k)
        {
            sorted.pop_front();
        }

        while (!sorted.empty() && numbers[sorted.back()] <= numbers[i])
        {
            sorted.pop_back();
        }

        sorted.push_back(i);

        if (i >= k - 1)
        {
            result.push_back(numbers[sorted.front()]);
        }
    }

    return result;
}

void print_result(vector<int> &numbers, int k)
{
    cout << "Res: ";
    for (auto num : running_max(numbers, k))
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> a;
    vector<int> b{1};
    vector<int> c{1, 2};
    vector<int> d{1, 2, 3};
    vector<int> e{3, 10, 5, 2, 7, 8, 7};
    vector<int> f{10, 5, 2, 7, 8, 7};

    print_result(a, 3);
    print_result(b, 2);
    print_result(c, 2);
    print_result(d, 3);
    print_result(e, 3);
    print_result(f, 3);
    print_result(f, 4);

    return 0;
}
