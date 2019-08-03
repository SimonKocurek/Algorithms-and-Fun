#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node(int data, node* next) : data(data), next(next) {}
};

int detect_loop(node* head) {
    if (head == nullptr) {
        throw;
    }

    auto slow = new node(0, head);
    auto fast = new node(1, head);

    while (fast != nullptr && fast->next != nullptr && slow->data != fast->data) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr) {
        throw;
    }
    
    slow = slow->next;
    while (head->data != slow->data) {
        slow = slow->next;
        head = head->next;
    }

    return slow->data;
}

int main() {
    auto a = new node(1, new node(2, new node(3, new node(4, nullptr))));
    auto b = new node(5, new node(6, new node(7, new node(8, new node(9, a->next->next->next)))));
    a->next->next->next->next = b;

    cout << detect_loop(a) << "\n";

    return 0;
}

