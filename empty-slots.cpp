#include <bits/stdc++.h>

using namespace std;

vector<int> load_flowers() {
    int pots;
    cin >> pots;

    vector<int> flowers(pots);
    for (auto& flower : flowers) {
        cin >> flower;
    }

    return flowers;
}

int time_with_space(vector<int>& flowers, int space) {
    if (space <= 0) {
        return 0;
    }

    if (flowers.size() < 3) {
        return -1;
    }

    return -1;
}

int main() {
    auto flowers = load_flowers();

    int space;
    cin >> space;

    cout << time_with_space(flowers, space) << endl;
    return 0;
}
