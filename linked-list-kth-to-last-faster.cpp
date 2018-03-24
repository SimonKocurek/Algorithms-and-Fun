/* Implement an algorithm to find the kth to last element of singly linked list. */

#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node(int data, node* next) : data(data), next(next) {}
};

int length(node* head) {
    int result = 0;

    while (head != nullptr) {
        head = head->next;
        result++;
    }

    return result;
}

node* kth_to_last(node* head, int k) {
    auto len = length(head);

    if (len - k - 1 < 0) {
        return nullptr;
    }

    for (int i = 0; i < len - k - 1; ++i) {
        if (head == nullptr) {
            break;
        }
        head = head->next;
    }

    return head;
}

int main() {
    node* a = nullptr;
    auto b = new node(1, nullptr);
    auto c = new node(1, new node(2, new node(3, new node(4, nullptr))));

    cout << kth_to_last(a, 0) << "\n";
    cout << kth_to_last(b, 1) << "\n";
    cout << kth_to_last(b, 0)->data << "\n";
    cout << kth_to_last(c, 0)->data << "\n";
    cout << kth_to_last(c, 2)->data << "\n";

    return 0;
}

