#include <bits/stdc++.h>

using namespace std;

int64_t find_wasted(vector<int>& pizzas, int people, int size) {
    int64_t eaten = (int64_t) people * size;
    int64_t all = 0;
    for (auto& pizza : pizzas) {
        all += pizza;
    }
    return all - eaten;
}

bool is_possible(vector<int>& pizzas, int people, int size) {
    int64_t unfed = people;

    for (auto& pizza : pizzas) {
        unfed -= pizza / size;

        if (unfed <= 0) {
            return true;
        }
    }

    return unfed <= 0;
}

int find_biggest(vector<int>& pizzas, int people) {
    int64_t start = 0;
    int64_t end = *max_element(pizzas.begin(), pizzas.end()) + 1;

    while ((start + 1) < end) {
        int64_t current = (start + end) / 2;
        if (is_possible(pizzas, people, current)) {
            start = current;
        } else {
            end = current;
        }
    }

    return start;
}

int main() {
    int pizza_count, people;
    cin >> pizza_count >> people;

    vector<int> pizzas(pizza_count);
    for (auto& pizza : pizzas) {
        cin >> pizza;
    }

    auto biggest = find_biggest(pizzas, people);
    auto wasted = find_wasted(pizzas, people, biggest);

    cout << biggest << "\n" << wasted << endl;
    return 0;
}
