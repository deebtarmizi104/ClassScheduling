#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

struct Process
{
   int ccode;     // course code
   int duration;      // class duration
   int priority;	//priority
   int arrival_time;   //prefered arrival time
};

//sort course priority
bool sortPriority (Process a, Process b){
	return(a.priority > b.priority);
}

// function to find the waiting time for all processes
void findWaitingTime(Process process[], int n, int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  process[i-1].duration + wt[i-1];
    }
}

// function to calculate turn around time
void findTurnAroundTime(Process process[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = process[i].duration + wt[i];
    }
}

// function to calculate average time
void findAverageTime(Process process[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // function to find waiting time of all processes
    findWaitingTime(process, n, wt);

    // function to find turn around time for all processes
    findTurnAroundTime(process, n, wt, tat);

    // display processes along with all details
    cout << "Course Code  "<< " Duration  "<< " Waiting time  " << " Turn around time\n";

    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << process[i].ccode << "\t\t" << process[i].duration <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = "<<fixed << setprecision(2) << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<<fixed << setprecision(2) << (float)total_tat / (float)n;
}

//priority scehduling
void PScheduling(Process process[], int n){
	//Sort processes by priority
	sort(process, process + n, sortPriority);
	
	cout << "Order in which processes gets executed \n";
	
	findAverageTime(process, n);
}

// main function
int main()
{
    // processes info
    Process process[] = {{2201, 3, 2, 1}, {3401, 2, 3, 2}, {1103, 1, 1, 3}};
    
	int n = sizeof process / sizeof process[0];

    PScheduling(process, n);

    return 0;
}
