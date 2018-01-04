#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct process {
  int id;
  int burst_time;
};

inline bool
operator<(const process &a, const process &b) {
  return a.burst_time < b.burst_time;
}

vector<process> processes;

int main() {
  int count;
  cin >> count;

  processes = vector<process>{count};
  for (auto &proc : processes) {
    cin >> proc.id >> proc.burst_time;
  }

  sort(processes.begin(), processes.end());
  int waited = 0;
  for (auto &proc : processes) {
    cout << "Process: " << proc.id << " (time: " << proc.burst_time << 
        ", wait: " << waited << ")\n";

    waited += proc.burst_time;
  }

  return 0;
}

