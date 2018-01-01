#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

typedef struct {
    int x, y, distance;
} point;

inline bool operator==(const point& a, const point& b)  {
    return a.x == b.x &&
           a.y == b.y;
}

inline bool valid(point& a, int size) {
    return a.x > 0 && a.x <= size &&
           a.y > 0 && a.y <= size;
}

int main() {
    int sets;
    cin >> sets;

    const int movements[][2]{{-2, 1}, {-2, -1},
                             {-1, 2}, {1, 2},
                             {2, 1}, {2, -1},
                             {-1, -2}, {1, -2}};

    for (int i = 0; i < sets; ++i) {
        int size, pieces;
        point start, end;
        cin >> size >> pieces >> start.x >> start.y >> end.x >> end.y;
        start.distance = 0;

        bool visited[size + 1][size + 1]{0};
        visited[start.y][start.x] = true;

        queue<point> search;
        search.push(start);

        for (int j = 0; j < pieces; ++j) {
            point piece;
            cin >> piece.x >> piece.y;
            visited[piece.y][piece.x] = true;
        }

        while(!search.empty() && !visited[end.y][end.x]) {
            point current = search.front();
            search.pop();
            
            for (int j = 0; j < 8; ++j) {
                point next = {current.x + movements[j][1], current.y + movements[j][0], current.distance + 1};

                if (!valid(next, size)) {
                    continue;
                }

                if (visited[next.y][next.x]) {
                    continue;
                }

                if (next == end) {
                    cout << next.distance << '\n';
                    visited[end.y][end.x] = true;
                    break;
                }

                search.push(next);
                visited[next.y][next.x] = true;
            }
        }

        if (!visited[end.y][end.x]) {
            cout << "neda sa\n";
        }
    }

    return 0;
}

