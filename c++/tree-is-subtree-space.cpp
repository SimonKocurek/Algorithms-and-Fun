#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {}
};

bool Same(const Node* a, const Node* b) {
  if (!a && !b) {
    return true;
  }

  return a && b && a->val == b->val && Same(a->left, b->left) && Same(a->right, b->right);
}

bool Subtree(Node* root, Node* subroot) {
  return Same(root, subroot) || 
    (root && (Subtree(root->left, subroot) || Subtree(root->right, subroot)));
}

int main() {
  auto sub_root = new Node(8,
      new Node(11,
        new Node(10, nullptr, nullptr),
        nullptr),
      new Node(12,
        new Node(20,
          new Node(22, nullptr, nullptr),
          nullptr),
        new Node(40, nullptr, nullptr)));

  auto root = new Node(8,
      new Node(11,
        new Node(33, nullptr, nullptr),
        new Node(43, nullptr, nullptr)),
      new Node(12,
        sub_root,
        new Node(20, nullptr, nullptr)));

  auto sub_root2 = new Node(8,
      new Node(11,
        new Node(10, nullptr, nullptr),
        nullptr),
      new Node(13,
        new Node(20,
          new Node(22, nullptr, nullptr),
          nullptr),
        new Node(40, nullptr, nullptr)));

  cout << Subtree(root, sub_root) << "\n";
  cout << Subtree(root, sub_root2) << "\n";

  return 0;
}

