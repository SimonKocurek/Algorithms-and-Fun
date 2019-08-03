#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct point {
    int x, y, distance;
};

inline bool operator<(const point& a, const point& b) {
    return a.distance < b.distance;
}

point load_point() {
    point current;
    cin >> current.x >> current.y;
    current.distance = current.x * current.x + current.y * current.y;

    return current;
}

int main() {
    int count, k;
    cin >> count >> k;

    priority_queue<point> result;
    int i = 0;
    for (; i < k; ++i) {
        result.push(load_point());
    }

    for (; i < count; ++i) {
        point current = load_point();
        if (result.top().distance > current.distance) {
            result.pop();
            result.push(current);
        }
    }

    while (!result.empty()) {
        point res = result.top();
        result.pop();
        cout << res.x << " " << res.y << '\n';
    }
    
    return 0;
}

