#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node (int data) : data(data) {}
};

int length(shared_ptr<Node> head) {
    auto result = 0;

    while (head != nullptr) {
        result++;
        head = head->next;
    }

    return result;
}

shared_ptr<Node> intersection(shared_ptr<Node> a, shared_ptr<Node> b) {
     auto size_a = length(a);
     auto size_b = length(b);

     while (size_a > size_b) {
         size_a--;
         a = a->next;
     }

     while (size_b > size_a) {
         size_b--;
         b = b->next;
     }

     while (a != b) {
         a = a->next;
         b = b->next;
     }

     return a;
}
    
int main() {
    auto head1 = make_shared<Node>(1);
    auto head2 = make_shared<Node>(2);
    
    cout << intersection(head1, head2) << "\n";

    auto current1 = head1;
    current1->next = make_shared<Node>(3);
    current1 = current1->next;

    auto current2 = head2;
    current2->next = make_shared<Node>(4);
    current2 = current2->next;
    current2->next = make_shared<Node>(5);
    current2 = current2->next;
    current2->next = make_shared<Node>(6);
    current2 = current2->next;
    current2->next = current1;
    current2 = current2->next;

    current2->next = make_shared<Node>(7);
    current2 = current2->next;
    current2->next = make_shared<Node>(8);;

    cout << intersection(head1, head2)->data << "\n";

    return 0;
}

