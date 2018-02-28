#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

uint16_t map[] = {
    0b1100110000000000,
    0b1110111000000000,
    0b0111011100000000,
    0b0011001100000000,
    0b1100110011000000,
    0b1110111011100000,
    0b0111011101110000,
    0b0011001100110000,
    0b0000110011001100,
    0b0000111011101110,
    0b0000011101110111,
    0b0000001100110011,
    0b0000000011001100,
    0b0000000011101110,
    0b0000000001110111,
    0b0000000000110011
};

uint16_t load_board() {
    uint16_t result = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c;
            cin >> c;

            result *= 2;
            result += c - '0';
        }
    }

    return result;
}

uint16_t flip_bit(int16_t board, int index) {
    return board ^= map[index];
}

int find_minimum(uint16_t board) {
    if (board == 0) {
        return 0;
    }

    unordered_map<uint16_t, int> states;
    queue<uint16_t> bfs;

    states[board] = 0;
    bfs.push(board);

    while (true) {
        board = bfs.front();
        bfs.pop();

        auto distance = states[board];

        for (int i = 0; i < 16; ++i) {
            auto new_board = flip_bit(board, i);

            if (states.find(new_board) != states.end()) {
                continue;
            }

            bfs.push(new_board);
            states[new_board] = distance + 1;

            if (new_board == 0) {
                return distance + 1;
            }
        }
    }

    return - 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    int sets;
    cin >> sets;

    for (int i = 0; i < sets; ++i) {
        auto board = load_board();
        auto min = find_minimum(board);
        cout << min << "\n";
    }

    return 0;
}

