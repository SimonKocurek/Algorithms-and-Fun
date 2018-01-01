#include <iostream>
#include <tuple>
#include <set>
#include <queue>

using namespace std;

struct state {
    int left_missionaries;
    int left_cannibals;
    int right_missionaries;
    int right_cannibals;
    bool boat_on_left;
};

typedef struct {
    state board_state;
    int moves;
} search_step;

inline bool operator<(const state &a, const state &b) {
    return tie(a.left_missionaries, a.right_missionaries, a.left_cannibals, a.right_cannibals, a.boat_on_left)
           <
           tie(b.left_missionaries, b.right_missionaries, b.left_cannibals, b.right_cannibals, b.boat_on_left);
}

bool valid_state(const state &checked_state) {
    return checked_state.left_cannibals > -1 &&
           checked_state.left_missionaries > -1 &&
           checked_state.right_cannibals > -1 &&
           checked_state.right_missionaries > -1 &&
           (checked_state.left_missionaries == 0 || checked_state.left_cannibals <= checked_state.left_missionaries) &&
           (checked_state.right_missionaries == 0 || checked_state.right_cannibals <= checked_state.right_missionaries);
}

bool final_state(const state &checked_state) {
    return checked_state.left_missionaries == 0 && checked_state.left_cannibals == 0;
}

void print_state(const state &printed_state) {
    cout << printed_state.left_missionaries
         << " "
         << printed_state.left_cannibals
         << (printed_state.boat_on_left ? " >>   " : "   << ")
         << printed_state.right_missionaries
         << " "
         << printed_state.right_cannibals
         << '\n';
}

int main() {
    int sets;
    cin >> sets;
    for (int i = 0; i < sets; ++i) {
        int missionaries, cannibals;
        cin >> missionaries >> cannibals;

        set<state> registered_states;
        queue<search_step> upcomming_states;

        const state starting_state = {missionaries, cannibals, 0, 0, true};
        registered_states.insert(starting_state);
        upcomming_states.push({starting_state, 0});

        int options[5][2] = {{1, 0},
                             {2, 0},
                             {0, 1},
                             {0, 2},
                             {1, 1}};

        bool finished = false;
        while (!upcomming_states.empty() && !finished) {
            const search_step current_state = upcomming_states.front();
            upcomming_states.pop();

            const int new_distance = current_state.moves + 1;
            const bool new_boat_position = !current_state.board_state.boat_on_left;

            for (auto &option : options) {
                const int direction = current_state.board_state.boat_on_left ? 1 : -1;

                const state new_state = {
                        current_state.board_state.left_missionaries - option[0] * direction,
                        current_state.board_state.left_cannibals - option[1] * direction,
                        current_state.board_state.right_missionaries + option[0] * direction,
                        current_state.board_state.right_cannibals + option[1] * direction,
                        new_boat_position
                };

                if (registered_states.find(new_state) == registered_states.end() && valid_state(new_state)) {
                    registered_states.insert(new_state);
                    upcomming_states.push({new_state, new_distance});

                    if (final_state(new_state)) {
                        cout << new_distance << '\n';
                        finished = true;
                        break;
                    }
                }
            }
        }

        if (!finished) {
            cout << "neda sa\n";
        }
    }

    return 0;
}

