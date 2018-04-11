#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Reconstruction;
typedef vector<Reconstruction> Reconstructions;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Print(Reconstructions printed) {
  for (auto& reconstruction : printed) {
    cout << "{";
    for (auto& value : reconstruction) {
      cout << value << ", ";
    }
    cout << "}\n";
  }
}

Reconstructions Reconstruct(Node* root) {

}

int main() {
  auto a = new Node(1,
      new Node(0,
        new Node(-2,
          new Node(8),
          nullptr),
        new Node(4)),
      new Node(3));

  auto b = new Node(2,
      new Node(1),
      new Node(3));

  auto c = new Node(2,
      new Node(1,
        new Node(0),
        nullptr),
      new Node(4,
        new Node(3),
        new Node(5)));

  Print(Reconstruct(a));
  Print(Reconstruct(b));
  Print(Reconstruct(c));

  return 0;
}

