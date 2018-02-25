#include <iostream>
#include <stack>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node(int data) : data(data) {}
};

int length(shared_ptr<Node> head) {
    auto length = 0;

    while (head != nullptr) {
        length++;
        head = head->next;
    }

    return length;
}

bool palindrome(shared_ptr<Node> head) {
    auto current = head;
    auto size = length(head);

    stack<int> values;
    for (auto i = 0; i < size / 2; ++i) {
        values.push(current->data);
        current = current->next;
    }

    if (size % 2 == 1) {
        current = current->next;
    }

    while (current != nullptr) {
        if (values.top() != current->data) {
            return false;
        }

        values.pop();
        current = current->next;
    }

    return true;
}

int main() {
    auto head = make_shared<Node>(1);
    cout << palindrome(head) << "\n";

    auto current = head;
    current->next = make_shared<Node>(2);
    cout << palindrome(head) << "\n";

    current = current->next;
    current->next = make_shared<Node>(3);
    cout << palindrome(head) << "\n";

    current = current->next;
    current->next = make_shared<Node>(2);
    cout << palindrome(head) << "\n";

    current = current->next;
    current->next = make_shared<Node>(1);
    cout << palindrome(head) << "\n";

    return 0;
}

