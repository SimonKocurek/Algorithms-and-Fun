#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {}
};

bool Subtree(Node* root, Node* subroot) {

}

int main() {
  auto root = new Node(1,
      new Node()

  auto sub_root = new Node(8,
    new Node()

  auto root2 = new Node(1;

  auto sub_root2 = new Node(8);


  cout << Subtree(root, sub_root) << "\n";
  cout << Subtree(root2, sub_root2) << "\n";

  return 0;
}

