#include <iostream>
#include <memory>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;
    
    Node(int data) : data(data) {}
};

void remove_duplicates(shared_ptr<Node> head) {
    unordered_set<int> seen;
    seen.insert(head->data);

    auto previous = head;
    auto current = head->next;
    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            previous->next = current->next;
            current = current->next;
            continue;
        }

        seen.insert(current->data);
        previous = current;
        current = current->next;
    }
}

bool value_before_current(shared_ptr<Node> start, shared_ptr<Node> end, int value) {
    auto current = start;
    while (current != end) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void remove_with_limited_memory(shared_ptr<Node> head) {
    auto current = head->next;
    auto previous = head;
    while (current != nullptr) {
        if (value_before_current(head, current, current->data)) {
            previous->next = current->next;
            current = current->next;
            continue;
        }

        previous = current;
        current = current->next;
    }
}

void print_linked_list(shared_ptr<Node> head) {
    auto current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    auto head = make_shared<Node>(1);
    auto current = head;
    for (int i = 0; i < 10; ++i) {
        current->next = make_shared<Node>(i);
        current = current->next;
    }
    for (int i = 5; i < 11; i += 2) {
        current->next = make_shared<Node>(i);
        current = current->next;
    }
    
    print_linked_list(head);
    remove_duplicates(head);
    print_linked_list(head);

    current = head;
    for (int i = 0; i < 15; ++i) {
        current->next = make_shared<Node>((i * 7) % 10);
        current = current->next;
    }
    print_linked_list(head);
    remove_with_limited_memory(head);
    print_linked_list(head);

    return 0;
}

