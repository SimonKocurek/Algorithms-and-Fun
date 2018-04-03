#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Traverse(Node* root, vector<int>& current, vector<vector<int>>& result) {
}

vector<vector<int>> Reconstructions(Node* root) {
  vector<vector<int>> result;

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

  cout << Trave
  return 0;
}

