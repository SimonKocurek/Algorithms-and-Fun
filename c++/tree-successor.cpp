#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node* parent;

	Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

Node* Deepest(Node* current) {
  while (current->left) {
    current = current->left;
  }

  return current;
}

Node* FirstRight(Node* parent, Node* child) {
  while (parent && parent->right == child) {
    child = parent;
    parent = parent->parent;
  }

  return parent;
}

Node* Successor(Node* node) {
	if (!node) {
		return nullptr;
	}

	if (node->right) {
    return Deepest(node->right);
	}

	if (node->parent) {
    return FirstRight(node->parent, node);
	}

	return nullptr;
}

int main() {
  auto a_l = new Node(2, nullptr, nullptr);
	auto a = new Node(4, a_l, nullptr);

	auto b_rrr = new Node(20, nullptr, nullptr);
	auto b_rrl = new Node(16, nullptr, nullptr);
	auto b_rr = new Node(18, b_rrl, b_rrr);
	auto b_rll = new Node(12, nullptr, nullptr);
	auto b_rl = new Node(14, b_rll, nullptr);
	auto b_r = new Node(15, b_rl, b_rr);
	auto b_lr = new Node(8, nullptr, nullptr);
	auto b_l = new Node(5, nullptr, b_lr);
	auto b = new Node(10, b_l, b_r);

	auto c_rl = new Node(8, nullptr, nullptr);
	auto c_r = new Node(15, c_rl, nullptr);
	auto c_lr = new Node(8, nullptr, nullptr);
	auto c_l = new Node(5, nullptr, c_lr);
	auto c = new Node(10, c_l, c_r);

  a_l->parent = a;

  b_l->parent = b;
  b_lr->parent = b_l;
  b_r->parent = b;
  b_rl->parent = b_r;
  b_rll->parent = b_rl;
  b_rr->parent = b_r;
  b_rrl->parent = b_rr;
  b_rrr->parent = b_rr;

  c_l->parent = c;
  c_lr->parent = c_l;
  c_r->parent = c;
  c_rl->parent = c_r;

  cout << Successor(a) << "\n";
  cout << Successor(a_l)->value << "\n";
  cout << Successor(b)->value << "\n";
  cout << Successor(b_l)->value << "\n";
  cout << Successor(b_lr)->value << "\n";
  cout << Successor(b_r)->value << "\n";
  cout << Successor(c)->value << "\n";
  cout << Successor(c_r) << "\n";

	return 0;
}

