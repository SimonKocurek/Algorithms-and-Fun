#include <bits/stdc++.h>

using namespace std;

class Node {
  private:
    bool locked;

    bool DescendantLocked() {
      if (left && (left->IsLocked() || left->DescendantLocked())) {
        return true;
      }

      if (right && (right->IsLocked() || right->DescendantLocked())) {
        return true;
      }

      return false;
    }

    bool TryChangingLock(bool new_lock) {
      if (AncestorLocked() || DescendantLocked()) {
        return false;
      }

      locked = new_lock;
      return true;
    }

  public:
    int value;
    Node* parent;

    Node* left;
    Node* right;

    Node(int value) : 
      locked(false), value(value), parent(nullptr), left(nullptr), right(nullptr) {}

    void AddLeft(Node* node) {
      left = node;
      left->parent = this;
    }

    void AddRight(Node* node) {
      right = node;
      right->parent = this;
    }

    bool IsLocked() {
      return locked;
    }

    bool AncestorLocked() {
      return parent && (parent->IsLocked() || parent->AncestorLocked());
    }

    bool Lock() {
      return TryChangingLock(true);
    }

    bool Unlock() {
      return TryChangingLock(false);
    }

};

int main() {
  auto tree = new Node(1);
  auto tree_l = new Node(2);
  auto tree_ll = new Node(3);
  auto tree_lr = new Node(3);
  auto tree_lrr = new Node(4);
  auto tree_r = new Node(2);
  auto tree_rr = new Node(3);
  auto tree_rrl = new Node(4);

  tree->AddLeft(tree_l);
  tree_l->AddLeft(tree_ll);
  tree_l->AddRight(tree_lr);
  tree_lr->AddRight(tree_lrr);
  tree->AddRight(tree_r);
  tree_r->AddRight(tree_rr);
  tree_rr->AddLeft(tree_rrl);

  cout << tree_r->Lock() << "\n";
  cout << tree_lr->Lock() << "\n";
  cout << tree_ll->Lock() << "\n";
  cout << tree_ll->Unlock() << "\n";

  cout << tree_rr->Lock() << "\n";
  cout << tree->Lock() << "\n";
  cout << tree_r->Unlock() << "\n";
  cout << tree->Lock() << "\n";

  return 0;
}

