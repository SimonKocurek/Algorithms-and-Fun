#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void crawl(int destination, int current, vector<int> &steps) {
    if (current == destination) {
        return;
    }

    if (current % 2 == 0) {
        if (steps[current / 2] > steps[current] + 1 && current / 2 >= destination) {
            steps[current / 2] = steps[current] + 1;
            crawl(destination, current / 2, steps);
        }
    }

    if (steps[current - 1] > steps[current] + 1 && current - 1 >= destination) {
        steps[current - 1] = steps[current] + 1;
        crawl(destination, current - 1, steps);
    }
}

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int start, end;
        cin >> start >> end;

        vector<int> steps(end + 1);
        fill(steps.begin(), steps.end(), 5001);
        steps[end] = 0;

        crawl(start, end, steps);
        cout << steps[start] << '\n';
    }

    return 0;
}

