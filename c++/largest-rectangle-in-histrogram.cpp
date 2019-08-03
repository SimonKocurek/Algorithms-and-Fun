#include <bits/stdc++.h>

using namespace std;

int largest_rectangle(vector<int> &histogram)
{
    int result = 0;
    stack<int> visited;

    for (int i = 0; i < histogram.size(); ++i)
    {
        if (visited.empty() || histogram[visited.top()] <= histogram[i])
        {
            visited.push(i);
        }
        else
        {
            while (histogram[visited.top()] > histogram[i])
            {
                int area = histogram[visited.top()] * (i - visited.top());
                visited.pop();

                result = max(result, area);
            }

            --i;
        }
    }

    while (!visited.empty())
    {
        int area = histogram[visited.top()] * (histogram.size() - visited.top());
        visited.pop();

        result = max(result, area);
    }

    return result;
}

int main()
{
    vector<int> a{1, 1, 2, 3, 4, 3, 1, 2, 2};
    vector<int> b{1, 2, 3, 4, 5, 3, 3, 2};

    cout << largest_rectangle(a) << "\n";
    cout << largest_rectangle(b) << "\n";

    return 0;
}
