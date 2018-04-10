#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int TreePaths(Node* tree, int target, int sum) {
  auto result = 0;

  auto new_sum = sum + tree->value;
  if (new_sum == target) {
    result++;
  }

  if (tree->left) {
    result += TreePaths(tree->left, target, new_sum);
  }
  if (tree->right) {
    result += TreePaths(tree->right, target, new_sum);
  }

  return result;
}

int Paths(Node* tree, int target) {
  auto result = 0;

  if (tree) {
    result += TreePaths(tree, target, 0);
    result += Paths(tree->left, target);
    result += Paths(tree->right, target);
  }

  return result;
}

int main() {
  auto root = new Node(1,
      new Node(2,
        new Node(2),
        new Node(8,
          new Node(0),
          new Node(1,
            new Node(-1),
            nullptr))),
      new Node(4,
        new Node(-3),
        new Node(5,
          new Node(2),
          nullptr)));

  cout << Paths(root, 5) << "\n";

  return 0;
}

