#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node (int data) : data(data) {}
};

void swap(shared_ptr<Node> a, shared_ptr<Node> b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void partition_list(shared_ptr<Node> head, int value) {
    auto less = head;
    auto current = head;

    while (current != nullptr) {
        if (current->data < value) {
            swap(less, current);
            less = less->next;
        }

        current = current->next;
    }
}

void print_list(shared_ptr<Node> head) {
    auto current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}

int main() {
    shared_ptr<Node> head = make_shared<Node>(3);
    auto current = head;
    int values[] = {5, 8, 5, 10, 2, 1};
    for (auto value : values) {
        current->next = make_shared<Node>(value);
        current = current->next;
    }

    print_list(head);
    partition_list(head, 5);
    print_list(head);
    return 0;
}

