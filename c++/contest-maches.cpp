#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int value;

	Node(int value) : left(nullptr), right(nullptr), value(value) { }
	Node(Node* left, Node* right) : left(left), right(right), value(0) { }

	void print() {
		if (value > 0) {
			cout << value;
		}
		else {
			cout << "(";
			left->print();
			cout << ", ";
			right->print();
			cout << ")";
		}
	}
};

void solve(int val) {
	if (val <= 0) {
		return;
	}

	vector<Node*> line;
	for (int i = 1; i <= val; ++i) {
		line.push_back(new Node(i));
	}

	val /= 2;
	while (val > 0) {
		vector<Node*> new_line;

		for (int i = 0; i < val; ++i) {
			new_line.push_back(new Node(line[i], line[line.size() - i - 1]));
		}

		val /= 2;
		line = new_line;
	}

	line.back()->print();
}

int main() {
	int val;
	cin >> val;

	solve(val);
}
