#include <bits/stdc++.h>

using namespace std;

struct Node {
  char name;
  vector<Node*> in;
  vector<Node*> out;

  Node(char name) : name(name) {}
};

vector<Node*> BuildGraph(vector<char>& projects, vector<pair<char, char>>& edges) {
  vector<Node*> graph(projects.size());

  for (auto name : projects) {
    graph[name - 'a'] = new Node(name);
  }

  for (auto edge : edges) {
    auto from = graph[edge.first - 'a'];
    auto to = graph[edge.second - 'a'];

    from->out.push_back(to);
    to->in.push_back(from);
  }

  return graph;
}

vector<char> BuildOrder(vector<char>& projects, vector<pair<char, char>>& dependencies) {
  vector<char> result;

  auto graph = BuildGraph(projects, dependencies);
  queue<Node*> removed;

  for (auto node : graph) {
    if (node->in.empty()) {
      removed.push(node);
    }
  }

  while (!removed.empty()) {
    auto current = removed.front();
    removed.pop();

    result.push_back(current->name);
    for (auto to : current->out) {
      auto& incomming = to->in;
      incomming.erase(remove(incomming.begin(), incomming.end(), current), incomming.end());

      if (incomming.empty()) {
        removed.push(to);
      }
    }
  }

  if (result.size() == projects.size()) {
    return result;
  }
}

int main() {
  vector<char> projects {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<pair<char, char>> dependencies {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};

  for (auto result : BuildOrder(projects, dependencies)) {
    cout << result << " ";
  }
  cout << "\n" << "Expected: e/f, b/a, d, c\n\n";

  vector<char> projects2 {'a', 'b', 'c', 'd'};
  vector<pair<char, char>> dependencies2 {{'a', 'b'}, {'b', 'c'}, {'c', 'a'}, {'a', 'd'}};

  for (auto result : BuildOrder(projects2, dependencies2)) {
    cout << result << " ";
  }
  cout << "\n" << "Expected: Nothing\n\n";

  vector<char> projects3 {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<pair<char, char>> dependencies3 {{'a', 'b'}, {'b', 'c'}, {'a', 'd'}, {'d', 'c'}, {'c', 'e'}, {'e', 'f'}, {'c', 'f'}};

  for (auto result : BuildOrder(projects3, dependencies3)) {
    cout << result << " ";
  }
  cout << "\n" << "Expected: a, b/d, c, e, f\n\n";

  return 0;
}

