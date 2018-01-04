#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int QUANTUM = 1;

struct process {
    int id;
    int burst_time;
    int waiting = 0;
};

inline bool operator<(const process &a, const process &b) {
    return a.waiting > b.waiting;
}

vector<process> processes;

int main() {
   uint32_t count;
   cin >> count;

   processes = vector<process>{count};
   for (auto &proc : processes) {
       cin >> proc.id >> proc.burst_time;
   }

   int time = 0;
   while (!processes.empty()) {
       sort(processes.begin(), processes.end());

       auto &executed = processes[0];
       executed.burst_time -= QUANTUM;

       for (int i = 1; i < processes.size(); ++i) {
           processes[i].waiting += QUANTUM;
       }

       if (executed.burst_time <= 0) {
           cout << "Process: " << executed.id << " (waited: " << executed.waiting
               << ")\n";

           processes.erase(processes.begin());
       }
   }

   return 0;
}
 
