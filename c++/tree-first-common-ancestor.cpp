#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* result;

int Traverse(Node* root, Node* p, Node* q) {
  if (!root) {
    return 0;
  }

  int got =
    (root == p) +
    (root == q) +
    Traverse(root->left, p, q) +
    Traverse(root->right, p, q);

  if (got == 2 && !result) {
    result = root;
  }

  return got;
}

Node* FindAncestor(Node* root, Node* p, Node* q) {
  result = nullptr;
  Traverse(root, p, q);
  return result;
}

int main() {
  auto a = new Node(-1,
      new Node(0,
        new Node(-2,
          new Node(8),
          nullptr),
        new Node(4)),
      new Node(3));
  auto p = a->left->left->left;
  auto q = a->left->right;

  cout << FindAncestor(a, p, q)->value << "\n";

  return 0;
}

