#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* next;

  Node(int value, Node* next) : value(value), next(next) {}
};

Node* RemoveKth(Node* head, int k) {
  auto result = new Node(0, head);

  auto current = result;
  auto forward = current->next;
  for (int i = 0; i < k; ++i) {
    current = forward;
    forward = forward->next;
  }

  current->next = forward->next;

  return result->next;
}

void Print(Node* head) {
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << "nullptr" << "\n";
}

int main() {
  auto a = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));
  auto b = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));
  auto c = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));
  auto d = new Node(1, nullptr);

  Print(RemoveKth(a, 0));
  Print(RemoveKth(b, 2));
  Print(RemoveKth(c, 3));
  Print(RemoveKth(d, 0));

  return 0;
}

