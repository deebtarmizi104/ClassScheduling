#include <iostream>
#include <iomanip>

using namespace std;
//structure for every process
struct Course {
   int ccode; // Process ID
   int duration; // Burst Time
   int arrival_time; // Arrival Time
};
void findTurnAroundTime(Course proc[], int n, int waiting_time[], int turn_around_time[]) {
   for (int i = 0; i < n; i++)
   turn_around_time[i] = proc[i].duration + waiting_time[i];
}
//waiting time of all process
void findWaitingTime(Course proc[], int n, int waiting_time[]) {
   int rt[n];
   for (int i = 0; i < n; i++)
   rt[i] = proc[i].duration;
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((proc[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      // decrementing the remaining time
      rt[shortest]--;
      minm = rt[shortest];
      if (minm == 0)
         minm = INT_MAX;
         // If a process gets completely
         // executed
         if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            waiting_time[shortest] = finish_time -
            proc[shortest].duration -
            proc[shortest].arrival_time;
            if (waiting_time[shortest] < 0)
               waiting_time[shortest] = 0;
         }
         // Increment time
         t++;
   }
}
// Function to calculate average time
void findavgTime(Course proc[], int n) {
   int waiting_time[n], turn_around_time[n], total_wt = 0,
   total_tat = 0;
   // Function to find waiting time of all
   // processes
   findWaitingTime(proc, n, waiting_time);
   // Function to find turn around time for
   // all processes
   findTurnAroundTime(proc, n, waiting_time, turn_around_time);
   cout << "Course Code " << " Duration " << " Waiting time " << " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + waiting_time[i];
      total_tat = total_tat + turn_around_time[i];
      cout << " " << proc[i].ccode << "\t\t" << proc[i].duration << "\t\t " << waiting_time[i] << "\t\t " << turn_around_time[i] << endl;
   }
   cout << "\nAverage waiting time = " << fixed << setprecision(2) << (float)total_wt / (float)n; 
   cout << "\nAverage turn around time = " << fixed << setprecision(2) << (float)total_tat / (float)n;
}
// main function
int main() {
   Course proc[] = { {2201, 3, 1}, {3401, 2, 2}, {1103, 1, 3} };
   int n = sizeof(proc) / sizeof(proc[0]);
   findavgTime(proc, n);
   return 0;
}
