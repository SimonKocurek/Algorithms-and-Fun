#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node(int data, node* next) : data(data), next(next) {}
};

bool delete_node(node* deleted) {
    if (deleted == nullptr || deleted->next == nullptr) {
        return false;
    }

    auto next = deleted->next;
    deleted->data = next->data;
    deleted->next = next->next;

    return true;
}

int main() {
    auto c = new node(1, new node(2, new node(3, new node(4, nullptr))));
    cout << delete_node(c->next->next) << "\n";

    while (c != nullptr) {
        cout << c->data << " ";
        c = c->next;
    }
    cout << '\n';

    return 0;
}

