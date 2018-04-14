#include <bits/stdc++.h>

using namespace std;

struct Rule {
    char from;
    string direction;
    char to;
};

struct Edge {
    char from, to;
};

struct Node {
    unordered_set<char> in, out;
};

const vector<Edge> VerticalEdges(const vector<Rule>& rules) {
    vector<Edge> result;

    for (auto& rule : rules) {
        if (rule.direction.front() == 'N') {
            result.push_back({rule.from, rule.to});
        }

        if (rule.direction.front() == 'S') {
            result.push_back({rule.to, rule.from});
        }
    }

    return result;
}

const vector<Edge> HorizontalEdges(const vector<Rule>& rules) {
    vector<Edge> result;

    for (auto& rule : rules) {
        if (rule.direction.back() == 'W') {
            result.push_back({rule.from, rule.to});
        }

        if (rule.direction.back() == 'E') {
            result.push_back({rule.to, rule.from});
        }
    }

    return result;
}

const unordered_map<char, Node> BuildGraph(const vector<Edge>& edges) {
    unordered_map<char, Node> result;

    for (auto& edge : edges) {
        auto& from = result[edge.from];
        auto& to = result[edge.to];

        from.out.insert(edge.to);
        to.in.insert(edge.from);
    }

    return result;
}

bool Topsort(unordered_map<char, Node>& graph) {
    queue<char> removed;
    int seen = 0;

    for (auto& entry : graph) {
        if (entry.second.in.empty()) {
            removed.push(entry.first);
        }
    }

    while (!removed.empty()) {
        auto current = removed.front();
        removed.pop();

        seen++;

        for (auto& visited : graph[current].out) {
            auto& to_visited = graph[visited].in;
            to_visited.erase(current);

            if (to_visited.empty()) {
                removed.push(visited);
            }
        }
    }

    return seen == graph.size();
}

bool Possible(const vector<Rule>& rules) {
    auto vertical_edges = VerticalEdges(rules);
    auto horizontal_edges = HorizontalEdges(rules);

    auto vertical_graph = BuildGraph(vertical_edges);
    auto horizontal_graph = BuildGraph(horizontal_edges);

    return Topsort(vertical_graph) && Topsort(horizontal_graph);
}

int main() {
    vector<Rule> test1 {{'A', "NE", 'B'}};
    vector<Rule> test2 {
        {'A', "N", 'B'},
        {'B', "NE", 'C'},
        {'C', "N", 'A'}
    };
    vector<Rule> test3 {
        {'A', "NW", 'B'},
        {'A', "N", 'B'}
    };
    vector<Rule> test4 {
        {'A', "N", 'B'},
        {'B', "N", 'A'}
    };
    vector<Rule> test5 {
        {'A', "N", 'B'},
        {'A', "S", 'B'}
    };
    vector<Rule> test6 {
        {'A', "N", 'B'},
        {'C', "N", 'B'}
    };
    vector<Rule> test7 {
        {'A', "N", 'B'},
        {'B', "S", 'A'},
        {'B', "N", 'C'},
        {'A', "N", 'C'},
        {'C', "S", 'B'},
        {'C', "S", 'A'}
    };

    cout << Possible(test1) << "\n";
    cout << Possible(test2) << "\n";
    cout << Possible(test3) << "\n";
    cout << Possible(test4) << "\n";
    cout << Possible(test5) << "\n";
    cout << Possible(test6) << "\n";
    cout << Possible(test7) << "\n";

    return 0;
}
