#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int count;
    cin >> count;
    
    int numbers[count];
    for (auto &number: numbers) {
        cin >> number;
    }

    int min = 0;
    int current = 0;
    int max = count - 1;

    while (current < max) {
        if (numbers[current] == 0) {
            current++;
            continue;
        }

        if (numbers[current] < 0) {
            swap(numbers[current], numbers[min]);
            current++;
            min++;
            continue;
        }
    
        if (numbers[current] > 0) {
            swap(numbers[current], numbers[max]);
            max--; 
        }
    }

    for (auto number: numbers) {
        cout << number << ' ';
    }

    return 0;
}

