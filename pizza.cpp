#include <iostream>

using namespace std;

bool possible(int pizza[], int pizzas, int people, int slice_size) {
    if (slice_size == 0) {
        return true;
    }

    for (int i = 0; i < pizzas; ++i) {
        people -= pizza[i] / slice_size;

        if (people <= 0) {
            return true;
        }
    }

    return false;
}

long binary_search(int pizza[], int pizzas, int people) {
    if (possible(pizza, pizzas, people, 1999999999)) {
        return 1999999999;
    }
        
    long start = 0;
    long  end = 1999999998;

    while (start <= end) {
        long cursor = (start + end) / 2;

        bool possible_now = possible(pizza, pizzas, people, cursor);
        if (possible_now && !possible(pizza, pizzas, people, cursor + 1)) {
            return cursor;
        }
        
        if (possible_now) {
            start = cursor;
            continue;
        }

        if (!possible_now) {
            end = cursor;
            continue;
        }
    }

    return 0;
}
    

int main() {
    int pizzas, people;
    cin >> pizzas >> people;

    int pizza[pizzas];
    for (int i = 0; i < pizzas; ++i) {
        cin >> pizza[i];
    }
    
    long largest_possible_slice = binary_search(pizza, pizzas, people);
    long remainder = 0;
    for (int i = 0; i < pizzas; ++i) {
        remainder += pizza[i];
    }
    remainder = remainder - people * largest_possible_slice;
        
    cout << largest_possible_slice << '\n' << remainder;
    return 0;
}

