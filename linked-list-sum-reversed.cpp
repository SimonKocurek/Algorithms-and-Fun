#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node(int data, node* next) : data(data), next(next) {}
};

node* sum(node* a, node* b) {
    stack<int> a_data;
    stack<int> b_data;

    while(a != nullptr) {
        a_data.push(a->data);
        a = a->next;
    }
    while(b != nullptr) {
        b_data.push(b->data);
        b = b->next;
    }

    auto result = new node(0, nullptr);
    auto carry = 0;

    while (!a_data.empty() || !b_data.empty()) {
        auto sum = carry;
        if (!a_data.empty()) {
            sum += a_data.top();
            a_data.pop();
        }
        if (!b_data.empty()) {
            sum += b_data.top();
            b_data.pop();
        }

        carry = sum / 10;
        auto next = new node(sum % 10, result->next);
        result->next = next;
    }

    if (carry == 1) {
        result->next = new node(carry, result->next);
    }

    return result->next;
}

int main() {
    node* a = nullptr;
    auto b = new node(1, nullptr);
    auto c = new node(1, new node(2, new node(3, new node(4, nullptr))));
    auto d = new node(7, new node(1, new node(6, nullptr)));
    auto e = new node(5, new node(9, new node(2, nullptr)));
    auto f = new node(1, new node(2, new node(3, new node(4, nullptr))));
    auto g = new node(5, new node(6, new node(7, nullptr)));

    auto res = sum(a, b);
    auto res2 = sum(b, c);
    auto res3 = sum(d, e);
    auto res4 = sum(f, g);

    while (res != nullptr) {
        cout << res->data << " ";
        res = res->next;
    }
    cout << "\n";

    while (res2 != nullptr) {
        cout << res2->data << " ";
        res2 = res2->next;
    }
    cout << "\n";

    while (res3 != nullptr) {
        cout << res3->data << " ";
        res3 = res3->next;
    }
    cout << "\n";

    while (res4 != nullptr) {
        cout << res4->data << " ";
        res4 = res4->next;
    }
    cout << "\n";

    return 0;
}

