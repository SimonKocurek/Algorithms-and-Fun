#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int Traverse(Node* tree, int target, unordered_map<int, int>& count, int running_sum) {
  if (!tree) {
    return 0;
  }

  running_sum += tree->value;
  count[running_sum]++;

  auto needed = running_sum - target;
  auto targeted = count[needed] +
    Traverse(tree->left, target, count, running_sum) +
    Traverse(tree->right, target, count, running_sum);

  count[running_sum]--;
  return targeted;
}

int Paths(Node* tree, int target) {
  unordered_map<int, int> count {{0, 1}};
  return Traverse(tree, target, count, 0);
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

