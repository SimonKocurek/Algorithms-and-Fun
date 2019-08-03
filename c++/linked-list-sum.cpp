#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node(int data, node* next) : data(data), next(next) {}
};

node* sum(node* a, node* b) {
    auto result = new node(0, nullptr);
    auto current = result;
    auto carry = 0;

    while (a != nullptr || b != nullptr) {
        auto sum = carry;
        if (a != nullptr) {
            sum += a->data;
            a = a->next;
        }

        if (b != nullptr) {
            sum += b->data;
            b = b->next;
        }

        current->next = new node(sum % 10, nullptr);
        current = current->next;
        carry = sum / 10;
    }

    if (carry > 0) {
        current->next = new node(1, nullptr);
    }

    return result->next;
}

int main() {
    node* a = nullptr;
    auto b = new node(1, nullptr);
    auto c = new node(1, new node(2, new node(3, new node(4, nullptr))));
    auto d = new node(7, new node(1, new node(6, nullptr)));
    auto e = new node(5, new node(9, new node(2, nullptr)));

    auto res = sum(a, b);
    auto res2 = sum(b, c);
    auto res3 = sum(d, e);

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
    return 0;
}

