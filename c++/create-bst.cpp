#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int data) : value(data) {}
};

Node* CreateBst(vector<int>& values, int start, int end) {
  if (start <= end) {
    int middle = (start + end) / 2;
    auto head = new Node(values[middle]);

    head->left = CreateBst(values, start, middle - 1);
    head->right = CreateBst(values, middle + 1, end);

    return head;
  }

  return nullptr;
}

Node* CreateBst(vector<int>& values) {
  return CreateBst(values, 0, values.size() - 1);
}

void Print(Node* bst, int indent) {
  for (int i = 0; i < indent; ++i) {
    cout << "->";
  }

  if (bst == nullptr) {
    cout << "nullptr" << "\n";
  } else {
    cout << bst->value << "\n";

    Print(bst->left, indent + 1);
    Print(bst->right, indent + 1);
  }
}

void Print(Node* bst) {
  Print(bst, 0);
  cout << "\n";
}

int main() {
  vector<int> a {1, 2, 3, 4};
  vector<int> b;
  vector<int> c {1, 3, 4};
  vector<int> d {1, 4};
  vector<int> e {1};

  Print(CreateBst(a));
  Print(CreateBst(b));
  Print(CreateBst(c));
  Print(CreateBst(d));
  Print(CreateBst(e));

  return 0;
}

