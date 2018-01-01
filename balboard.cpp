#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct offer {
    int start;
    int end;
    int payment;
    string name;
};

inline bool operator<(const offer& a, const offer& b) {
    return a.end < b.end;
}

int binary_search(offer adverts[], int current) {
    int start = 0;
    int end = current - 1;

    while (start <= end) {
        int half_point = (start + end) / 2;
       
        if (adverts[half_point].end > adverts[current].start) {
            end = half_point - 1;
            continue;
        }

        if (adverts[half_point + 1].end > adverts[current].start) {
            return half_point;
        } else {
            start = half_point + 1;
        }
    }

    return -1;
}

int main() {
    int requests;
    cin >> requests;
    
    if (requests == 0) {
        cout << "0 0\n";
        return 0;
    }

    offer adverts[requests];
    for (int i = 0; i < requests; ++i) {
        auto& add = adverts[i];
        cin >> add.start >> add.end >> add.payment >> add.name;
        add.end += add.start;
    }

    sort(adverts, adverts + requests);
    
    int closest_possible[requests];
    for (int i = 0; i < requests; ++i) {
       closest_possible[i] = binary_search(adverts, i);
    }

    int optimal_payment[requests];
    optimal_payment[0] = adverts[0].payment;
    for (int i = 1; i < requests; ++i) {
       optimal_payment[i] = adverts[i].payment;

       if (closest_possible[i] != -1) {
           optimal_payment[i] += optimal_payment[closest_possible[i]];
       }

       optimal_payment[i] = max(optimal_payment[i], optimal_payment[i - 1]);
    }

    int& profit = optimal_payment[requests - 1];
    int optimum = 0;
    for (int i = 1; i < requests; ++i) {
        if (optimal_payment[i] > optimal_payment[optimum]) {
            optimum = i;
        }
    }

    int i = optimum;
    vector<offer> taken;
    while (i >= 0) {
        taken.push_back(adverts[i]);

        int ancestor = closest_possible[i];
        for (int j = ancestor - 1; j >= 0; --j) {
            if (optimal_payment[j] >= optimal_payment[ancestor]) {
                ancestor = j;
            }
        }
        i = ancestor;
    }

    cout << taken.size() << " " << profit << '\n';
    for (auto& taken_offer : taken) {
        cout << taken_offer.start << " " << taken_offer.end << " " << taken_offer.name << '\n';
    }

    return 0;
}

