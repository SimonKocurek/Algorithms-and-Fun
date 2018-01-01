#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef struct {
    int server;
    int latency;
} connection;

typedef struct {
    int from;
    int total_latency;
} possible_path;

inline bool operator<(const possible_path &a, const possible_path &b) {
    return a.total_latency > b.total_latency;
}

int main() {
    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        int servers, edges, start, end;
        cin >> servers >> edges >> start >> end;

        vector<connection> server[servers];
        for (int j = 0; j < edges; ++j) {
            int from, to, lattency;
            cin >> from >> to >> lattency;

            server[from].push_back({to, lattency});
            server[to].push_back({from, lattency});
        }

        int distance[servers];
        for (int k = 0; k < servers; ++k) {
            distance[k] = INT32_MAX;
        }

        priority_queue<possible_path> possibilities;
        set<int> optimal;

        distance[start] = 0;
        possibilities.push({start, 0});

        while (!possibilities.empty()) {
            possible_path current = possibilities.top();
            possibilities.pop();

            // got already optimal point
            if (optimal.find(current.from) != optimal.end()) {
                continue;
            }

            optimal.insert(current.from);

            if (current.from == end) {
                break;
            }

            for (auto &connected_server : server[current.from]) {
                if (optimal.find(connected_server.server) != optimal.end()) {
                    continue;
                }

                const int new_latency = current.total_latency + connected_server.latency;

                if (distance[connected_server.server] > new_latency) {
                    possibilities.push({connected_server.server, new_latency});
                    distance[connected_server.server] = new_latency;
                }
            }
        }

        cout << "Case #" << i + 1 << ": ";
        if (distance[end] == INT32_MAX) {
            cout << "unreachable";
        } else {
            cout << distance[end];
        }
        cout << '\n';
    }

    return 0;
}
