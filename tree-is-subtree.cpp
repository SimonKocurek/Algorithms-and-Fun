#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {}
};

string Preorder(Node* root) {
  if (!root) {
    return "";
  }

  return to_string(root->val) + ',' + Preorder(root->left) + ',' + Preorder(root->right);
}

bool Subtree(Node* root, Node* subroot) {
  auto bigger = Preorder(root);
  auto smaller = Preorder(subroot);

  return bigger.find(smaller) != string::npos;
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

