#include <bits/stdc++.h>

using namespace std;

// Sorting based on 1 or 2 stack and no other data structures
template<class T>
void sort_stack(stack<T> &sorted) {
    stack<T> secondary;

    while (!sorted.empty()) {
        auto inserted = sorted.top();
        sorted.pop();

        while (!secondary.empty() && secondary.top() > inserted) {
            sorted.push(secondary.top());
            secondary.pop();
        }

        secondary.push(inserted);

        while (!sorted.empty() && sorted.top() >= secondary.top()) {
            secondary.push(sorted.top());
            sorted.pop();
        }
    }

    while (!secondary.empty()) {
        sorted.push(secondary.top());
        secondary.pop();
    }
}

int main() {
    stack<int> a;
    int a_values[] {34, 3, 31, 98, 92, 23};
    for (auto i : a_values) {
        a.push(i);
    }

    stack<int> b; 
    int b_values[] {3, 5, 1, 4, 2, 8};
    for (auto i : b_values) {
        b.push(i);
    }

    sort_stack(a);
    sort_stack(b);

    while (!a.empty()) {
        auto i = a.top();
        a.pop();

        cout << i << " ";
    }
    cout << "\n";

    while (!b.empty()) {
        auto i = b.top();
        b.pop();

        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

