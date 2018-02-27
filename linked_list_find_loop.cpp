#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node (int data) : data(data) {}
};

shared_ptr<Node> meeting_point(shared_ptr<Node> head, shared_ptr<Node> cursor) {
    while (head != cursor) {
        head = head->next;
        cursor = cursor->next;
    }

    return cursor;
}

shared_ptr<Node> find_loop(shared_ptr<Node> head) {
    auto faster = head;
    auto slower = head;

    while (faster->next != nullptr && faster->next->next != nullptr) {
        faster = faster->next->next;
        slower = slower->next;

        if (faster == slower) {
            return meeting_point(head, faster);
        }
    }

    return nullptr;
}

int main() {
    auto head = make_shared<Node>(1);
    auto current = head;
    for (int i = 2; i < 10; ++i) {
        current->next = make_shared<Node>(i);
        current = current->next;
    }

    auto fourth = head;
    for (int i = 0; i < 3; ++i) {
        fourth = fourth->next;
    }

    current->next = fourth; 
    
    cout << find_loop(head)->data << "\n";

    return 0;
}

