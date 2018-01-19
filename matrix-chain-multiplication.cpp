#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct matrice {
  int start;
  int end;
};

vector<matrice> matrices;
string result;

void load() {
  uint32_t dimension_count;
  cin >> dimension_count;

  matrices = vector<matrice>(dimension_count - 1);
  cin >> matrices.begin()->start;
  for (int j = 0; j < dimension_count - 2; ++j) {
    int dimension;
    cin >> dimension;

    matrices[j].end = dimension;
    matrices[j + 1].start = dimension;
  }
  cin >> matrices.end()->end;
}

void fill_minimal_multiplications(vector<vector<int>> &table) {
  
}

void calculate_result() {
  vector<vector<int>> table(matrices.size(), vector<int>(matrices.size()));
  fill_minimal_multiplications(table);

  
}

int main() {
  int sets;
  cin >> sets;

  for (int i = 0; i < sets; ++i) {
    load();
    calculate_result();
    cout << result << '\n';
  }

  return 0;
}

