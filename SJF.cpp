#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct Course {
   int ccode; // course code
   int duration; // class duration
   int arrival_time; // prefered arrival time
};

void findTurnAroundTime(Course process[], int n, int waiting_time[], int turn_around_time[]) {
   for (int i = 0; i < n; i++)
   turn_around_time[i] = process[i].duration + waiting_time[i];
}
//waiting time of classes
void findWaitingTime(Course process[], int n, int waiting_time[]) {
   int remaining_time[n];
   for (int i = 0; i < n; i++)
   remaining_time[i] = process[i].duration;
   int complete = 0, t = 1, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((process[j].arrival_time <= t) && (remaining_time[j] < minm) && remaining_time[j] > 0) {
            minm = remaining_time[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      // decrement the remaining time
      remaining_time[shortest]--;
      minm = remaining_time[shortest];
      if (minm == 0)
         minm = INT_MAX;
         if (remaining_time[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            waiting_time[shortest] = finish_time - process[shortest].duration -process[shortest].arrival_time;
            if (waiting_time[shortest] < 0)
               waiting_time[shortest] = 0;
         }
         // Increment time
         t++;
   }
}
// Function to calculate average time
void findaverageTime(Course process[], int n) {
   int waiting_time[n], turn_around_time[n], total_wt = 0,
   total_tat = 0;
   // Function to find waiting time 
   findWaitingTime(process, n, waiting_time);
   // Function to find turn around time
   findTurnAroundTime(process, n, waiting_time, turn_around_time);
   cout << "Course Code " << " Duration " << " Waiting time " << " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + waiting_time[i];
      total_tat = total_tat + turn_around_time[i];
      cout << " " << process[i].ccode << "\t\t" << process[i].duration << "\t\t " << waiting_time[i] << "\t\t " << turn_around_time[i] << endl;
   }
	cout << "\nAverage waiting time = " << fixed << setprecision(2) << (float)total_wt / (float)n; 
   	cout << "\nAverage turn around time = " << fixed << setprecision(2) << (float)total_tat / (float)n;
   }
// main function
int main() {
   Course process[] = { {2201, 3, 1}, {3401, 2, 2}, {1103, 1, 3} };
   int n = sizeof(process) / sizeof(process[0]);
   
   cout << "Order of scheduling for the courses:\n";
   
   findaverageTime(process, n);
   return 0;
}
