#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll variable_steps(vector<int> &step_sizes, int stairs)
{
    vector<ll> possibilities(stairs + 1, 0);
    possibilities[0] = 1;

    for (int i = 1; i < stairs + 1; ++i)
    {
        for (auto &step : step_sizes)
        {
            if (i - step < 0)
            {
                continue;
            }

            possibilities[i] += possibilities[i - step];
        }
    }

    return possibilities.back();
}

int main()
{
    vector<int> steps{1, 3, 5};
    vector<int> step{1};

    cout << variable_steps(steps, 0) << "\n";
    cout << variable_steps(steps, 1) << "\n";
    cout << variable_steps(steps, 10) << "\n";
    cout << variable_steps(step, 1) << "\n";
    cout << variable_steps(step, 10) << "\n";

    return 0;
}
