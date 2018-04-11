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
  cout << "\n";
}

Reconstructions Weave(Reconstruction left, Reconstruction right) {
  Reconstructions result;

  if (left.empty() && right.empty()) {
    result.emplace_back();
    return result;
  }

  if (right.empty()) {
    result.push_back(left);
    return result;
  }

  if (left.empty()) {
    result.push_back(right);
    return result;
  }

  auto woven_left = Weave(Reconstruction(left.begin() + 1, left.end()), right);
  for (auto woven : woven_left) {
    Reconstruction added {left[0]};
    added.insert(added.end(), woven.begin(), woven.end());
    result.push_back(added);
  }

  auto woven_right = Weave(left, Reconstruction(right.begin() + 1, right.end()));
  for (auto woven : woven_right) {
    Reconstruction added {right[0]};
    added.insert(added.end(), woven.begin(), woven.end());
    result.push_back(added);
  }

  return result;
}

Reconstructions Combine(
    Reconstructions left, 
    Reconstructions right,
    const int value) {
  Reconstructions result;
  
  if (left.empty()) {
    left.emplace_back();
  }

  if (right.empty()) {
    right.emplace_back();
  }

  for (const auto& left_reconstruction : left) {
    for (const auto& right_reconstruction : right) {

      for (auto& woven : Weave(left_reconstruction, right_reconstruction)) {
        woven.insert(woven.begin(), value);
        result.push_back(woven);
      }

    }
  }

  return result;
}

Reconstructions Reconstruct(const Node* root) {
  Reconstructions result;

  if (root) {
    auto left = Reconstruct(root->left);
    auto right = Reconstruct(root->right);

    for (auto& reconstruction : Combine(left, right, root->value)) {
      result.push_back(reconstruction);
    }
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

