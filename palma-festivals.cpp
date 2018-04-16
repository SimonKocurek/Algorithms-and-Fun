#include <bits/stdc++.h>

using namespace std;

struct Festival {
    int start, end, price;
};

int main() {
    int festival_count, limit;
    cin >> festival_count >> limit;

    vector<Festival> festivals(festival_count);
    for (auto& festival : festivals) {
        int start, end, price;
        cin >> start >> end >> price;

        festival = {start, end, price};
    }


    return 0;
}
