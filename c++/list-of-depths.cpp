#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void Traverse(vector<list<int>>& result, Node* tree, int depth) {
  if (tree == nullptr) {
    return;
  }

  if (result.size() == depth) {
    result.emplace_back();
  }
  result[depth].push_back(tree->value);

  Traverse(result, tree->left, depth + 1);
  Traverse(result, tree->right, depth + 1);
}

vector<list<int>> DepthLists(Node* tree) {
  vector<list<int>> result;
  Traverse(result, tree, 0);
  return result;
}

void Print(vector<list<int>>& lists) {
  for (auto& l : lists) {
    while (!l.empty()) {
      cout << l.front() << "->";
      l.pop_front();
    }
    cout << "nullptr" << "\n";
  }
}

int main() {
  auto tree = new Node(0, 
      new Node(1, 
        new Node(2, nullptr, nullptr),
        new Node(2, 
          nullptr,
          new Node(3, nullptr, nullptr))),
      new Node(1,
        new Node(2, 
          nullptr,
          new Node(3,
            nullptr,
            new Node(4, nullptr, nullptr))),
        new Node(2, nullptr, nullptr)));

  auto result = DepthLists(tree);
  Print(result);

  return 0;
}

