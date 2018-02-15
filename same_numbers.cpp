#include <vector>
#include <iostream>

void print_same(std::vector<int> &a, std::vector<int> &b) {
    int a_index = 0;
    int b_index = 0;

    while (a_index < a.size() && b_index < b.size()) {
        if (a[a_index] == b[b_index]) {
            std::cout << a[a_index] << " " << b[b_index] << '\n';
            a_index++;
            b_index++;
        } else if (a[a_index] < b[b_index]) {
            a_index++;
        } else {
            b_index++;
        }
    }
}

int main() {
    std::vector<int> a {13, 27, 35, 40, 49, 55, 59};
    std::vector<int> b {17, 35, 39, 40, 55, 58, 60};

    print_same(a, b);
    return 0;
}

