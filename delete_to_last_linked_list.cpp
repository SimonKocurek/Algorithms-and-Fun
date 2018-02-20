#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node(int data) : data(data) {}
};

shared_ptr<Node> delete_to_last(shared_ptr<Node> head, int k) {
    if (k < 0) {
        throw invalid_argument("K must be positive. Got " + k);
    }

    auto current = head;
    for (int i = 0; i < k; ++i) {
        current = current->next;
        if (current == nullptr) {
            throw;
        }
    }

    if (current->next == nullptr) {
        return head->next;
        }
    
    auto before_deleted = head;
    current = current->next;
    while (current->next != nullptr) {
        current = current->next;
        before_deleted = before_deleted->next;
    }
    
    before_deleted->next = before_deleted->next->next;
    return head;
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
    shared_ptr<Node> head = make_shared<Node>(0);
    auto current = head;
    for (int i = 1; i < 14; ++i) {
        current->next = make_shared<Node>(i);
        current = current->next;
    }

    cout << "Base: ";
    print_list(head);

    cout << "4: ";

    head = delete_to_last(head, 4);
    print_list(head);
    cout << "0: ";

    head = delete_to_last(head, 0);
    print_list(head);

    cout << "11: ";
    head = delete_to_last(head, 11);
    print_list(head);

    return 0;
}

