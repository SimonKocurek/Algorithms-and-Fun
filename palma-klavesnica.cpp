#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> Locations;

const int alphabet = 'Z' - 'A' + 1;

struct Move {
    int cost;
    int word_idx;
    Point location;

    inline const bool operator<(const Move& a) const {
        return cost > a.cost;
    }
};

vector<Locations> LoadLocations(const int y, const int x) {
    vector<Locations> result(alphabet);

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            char c;
            cin >> c;

            result[c - 'A'].push_back({i, j});
        }
    }

    return result;
}

int distance(const Point a, const Point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void Solve(const vector<Locations>& loactions, const string& word, const int y, const int x, const int y_max, const int x_max) {
    vector<vector<vector<bool>>> visited(word.size() + 1, vector<vector<bool>>(y_max, vector<bool>(x_max, false)));

    priority_queue<Move> next;
    next.push({0, 0, {y, x}});

    int min = INT_MAX;

    while (!next.empty()) {
        auto current = next.top();
        next.pop();

        if (visited[current.word_idx][current.location.first][current.location.second]) {
            continue;
        } else {
            visited[current.word_idx][current.location.first][current.location.second] = true;
        }
        
        if (current.word_idx == word.size()) {
            min = std::min(min, current.cost);
            continue;
        }

        auto next_char = word[current.word_idx];
        for (auto& location : loactions[next_char - 'A']) {
            if (visited[current.word_idx + 1][location.first][location.second]) {
                continue;
            }
            
            auto new_cost = current.cost + distance(current.location, location) + 1;
            next.push({new_cost, current.word_idx + 1, location});
        }
    }

    cout << min << "\n";
}

int main() {
    int y, x, word_count;
    cin >> y >> x >> word_count;

    auto locations = LoadLocations(y, x);
    for (int i = 0; i < word_count; ++i) {
        int start_y, start_x;
        string word;

        cin >> start_y >> start_x >> word;
        Solve(locations, word, start_y, start_x, y, x);
    }

    return 0;
}
