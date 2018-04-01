#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

struct NodeInfo {
  int min;
  int max;
  bool bst;
};

NodeInfo Traverse(Node* root) {
  NodeInfo current = {root->value, root->value, true};

  if (root->left) {
    auto left = Traverse(root->left);

    current.bst = current.bst && left.bst && left.max < root->value;
    current.min = min(left.min, current.min);
    current.max = max(left.max, current.max);
  }

  if (root->right) {
    auto right = Traverse(root->right);

    current.bst = current.bst && right.bst && right.min > root->value;
    current.min = min(right.min, current.min);
    current.max = max(right.max, current.max);
  }

  return current;
}

bool IsBst(Node* root) {
  return !root || Traverse(root).bst;
}

int main() {
  auto a = new Node(4, new Node(2, nullptr, nullptr), nullptr);
  auto b = new Node(10, 
      new Node(5, nullptr, new Node(8, nullptr, nullptr)),
      new Node(15,
        new Node(14, new Node(12, nullptr, nullptr), nullptr),
        new Node(18,
          new Node(16, nullptr, nullptr), 
          new Node(20, nullptr, nullptr))));
  auto c = new Node(10, 
      new Node(5, nullptr, new Node(8, nullptr, nullptr)),
      new Node(15, new Node(8, nullptr, nullptr), nullptr));

  cout << IsBst(a) << "\n";
  cout << IsBst(b) << "\n";
  cout << IsBst(c) << "\n";

  return 0;
}

