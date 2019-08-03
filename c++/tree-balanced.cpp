#include <bits/stdc++.h>

using namespace std;

struct Balance {
  int size;
  bool balanced;
};

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
};

Balance SubtreeBalance(Node* root) {
  Balance left_balance = {0, true};
  Balance right_balance = {0, true};

  if (root->left) {
    left_balance = SubtreeBalance(root->left);
  }

  if (root->right) {
    right_balance = SubtreeBalance(root->right);
  }

  bool balanced = left_balance.balanced &&
    right_balance.balanced &&
    abs(left_balance.size - right_balance.size) <= 1;

  return {1 + left_balance.size + right_balance.size, balanced};
}

bool Balanced(Node* root) {
  return root && SubtreeBalance(root).balanced;
}

int main() {
  cout << Balanced(new Node(1, 
        new Node(2,
          new Node(3, nullptr, nullptr), 
          new Node(3, nullptr, nullptr)),
        new Node(2, 
          new Node(3, nullptr, nullptr)
          , nullptr))) << "\n";
  cout << Balanced(nullptr) << "\n";
  cout << Balanced(new Node(1, 
        new Node(2,
          new Node(3, nullptr, nullptr), 
          new Node(3, nullptr, nullptr)),
        new Node(2, nullptr, nullptr))) << "\n";

  return 0;
}

