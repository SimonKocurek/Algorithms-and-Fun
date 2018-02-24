#include <iostream>
#include <stack>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node(int data) : data(data) {}
};

void print_linked_list(shared_ptr<Node> head) {
    auto current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}

shared_ptr<Node> sum(shared_ptr<Node> a, shared_ptr<Node> b) {
    auto head = make_shared<Node>((a->data + b->data) % 10);
    auto carry = (a->data + b->data) / 10;
    auto current = head;

    a = a->next;
    b = b->next;
    while (a != nullptr || b != nullptr) {
        int sum = carry;
        carry = 0;

        if (a != nullptr) {
            sum += a->data;
            carry += a->data;
            a = a->next;
        }

        if (b != nullptr) {
            sum += b->data;
            carry += b->data;
            b = b->next;
        }

        carry = carry / 10;
        sum = sum % 10;
        current->next = make_shared<Node>(sum);
        current = current->next;
    }

    return head;
}

shared_ptr<Node> reverse(shared_ptr<Node> head) {
    stack<int> values;
    auto current = head;
    while (current != nullptr) {
        values.push(current->data);
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        current->data = values.top();
        values.pop();
        current = current->next;
    }

    return head;
}

shared_ptr<Node> sum_reversed(shared_ptr<Node> a, shared_ptr<Node> b) {
    reverse(a);
    reverse(b);

    return reverse(sum(a, b));
}

int main() {
    auto head1 = make_shared<Node>(7);
    auto head2 = make_shared<Node>(5);

    auto head3 = make_shared<Node>(6);
    auto head4 = make_shared<Node>(2);

    auto current = head1;
    current->next = make_shared<Node>(1);
    current = current->next;
    current->next = make_shared<Node>(6);

    current = head2;
    current->next = make_shared<Node>(9);
    current = current->next;
    current->next = make_shared<Node>(2);

    current = head3;
    current->next = make_shared<Node>(1);
    current = current->next;
    current->next = make_shared<Node>(7);

    current = head4;
    current->next = make_shared<Node>(9);
    current = current->next;
    current->next = make_shared<Node>(5);

    print_linked_list(head1);
    print_linked_list(head2);
    print_linked_list(sum(head1, head2));

    cout << "\n";

    print_linked_list(head3);
    print_linked_list(head4);
    auto reversed = sum_reversed(head3, head4);
    print_linked_list(reversed);

    return 0;
}

