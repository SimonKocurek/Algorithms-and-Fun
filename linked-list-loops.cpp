#include <iostream>
#include <unordered_set>
#include <memory>

using namespace std;

struct Node {
  int data;
  shared_ptr<Node> next;
};

int main() {
  int sets;
  cin >> sets;

  for (int i = 0; i < sets; ++i) {
    int count;
    cin >> count;

    auto head = make_shared<Node>();
    cin >> head->data;

    auto current = head;
    for (int j = 1; j < count; ++j) {
      current->next = make_shared<Node>();
      current = current->next;

      cin >> current->data;
    }

    int last_connection;
    cin >> last_connection;

    auto connected = head;
    for (int j = 0; j < last_connection; ++j) {
      connected = connected->next;
    }

    current->next = connected;

    unordered_set<shared_ptr<Node>> visited_notes;
    auto traversed = head;
    while (traversed != nullptr) {
      if (visited_notes.find(traversed->next) == visited_notes.end()) {
        traversed->next = nullptr;
      }

      visited_notes.insert(traversed);
      traversed = traversed->next;
    }

    cout << 1 << '\n';
  }

  return 0;
}

