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
    for (auto& value : reconstruction) {
      cout << value << " ";
    }
    cout << "\n";
  }
}

void Extend(Reconstruction& base, Reconstruction& next) {
  base.insert(base.end(), next.begin(), next.end());
}

void Add(Reconstructions& left, Reconstructions& right, int root, Reconstructions& result) {
  for (auto& left_reconstruction : left) {
    Reconstruction added {root};
    Extend(added, left_reconstruction);

    auto left_part_size = added.size();
    for (auto& right_reconstruction : right) {
      added.resize(left_part_size);
      Extend(added, right_reconstruction);
      result.push_back(added);
    }
  }
}

void Add(Reconstructions& single, int root, Reconstructions& result) {
  for (auto& reconstruction: single) {
    Reconstruction added {root};
    Extend(added, reconstruction);

    result.push_back(added);
  }
}

void Add(int root, Reconstructions& result) {
  result.push_back(Reconstruction {root});
}

void AddNoneEmpty(
    Reconstructions& left,
    Reconstructions& right,
    int root,
    Reconstructions& result) {

  if (!right.empty() && !left.empty()) {
    Add(right, left, root, result);
    Add(left, right, root, result);

  } else if (!right.empty()) {
    Add(right, root, result);

  } else if (!left.empty()) {
    Add(left, root, result);

  } else {
    Add(root, result);
  }
}

Reconstructions Reconstruct(Node* root) {
  Reconstructions result;

  if (root) {
    auto left = Reconstruct(root->left);
    auto right = Reconstruct(root->right);

    AddNoneEmpty(left, right, root->value, result);
  }

  return result;
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

