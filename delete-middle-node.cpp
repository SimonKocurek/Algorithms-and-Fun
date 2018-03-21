#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node (int data) : data(data) {}
};

void delete_node(shared_ptr<Node> node) {
    auto current = node;
    while(current->next->next != nullptr) {
        current->data = current->next->data;
        current = current->next;
    }

    current->data = current->next->data;
    current->next = nullptr;
}

void print_liked_list(shared_ptr<Node> head) {
    auto current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    shared_ptr<Node> head = make_shared<Node>(0);
    auto current = head;
    for (int i = 1; i < 4; ++i) {
        current->next = make_shared<Node>(i);
        current = current->next;
    }

    auto deleted = current;

    for (int i = 4; i < 8; ++i) {
        current->next = make_shared<Node>(i);
        current = current->next;
    }

    print_liked_list(head);
    delete_node(deleted);
    print_liked_list(head);

    return 0;
}

