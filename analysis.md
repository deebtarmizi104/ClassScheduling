# Group Members

1. Ami Dilaperuri Nasir  1726782
2. Nur Iwana Binti Ahmad Radzi 1812984
3. Wan Nurul Adibah binti Wan Tarmizi 1814162

# Introduction

  In computing, scheduling method by which work is assigned to resources that complete the work. The work may be virtual computation elements such as threads, processes or data flows. Scheduling is fundamental to computing itself, and an essential part of the computer system execution model; the scheduling concept makes it possible to have multitasking computers with a single central processing unit. In this paper, we analyze the scheduling method specified in class scheduling using 3 algorithm which is FCFS, SJF, and Priority Scheduling.  Class scheduling is same as CPU scheduling but Class scheduling is non-preemptive algorithm. And we choose the  appropriate algorithm for the case that does not have to prior any process to be prioritized at first. 

# Consideration

Describe what you have considered

# Analysis


| Course Code| Arrival Time | Duration | Priority |
| :---------------: | :---------------: | :---------------: | :----------------: |
| 2201 | 1 | 3 | 2 |
| 3401 | 2 | 2 | 3 |
| 1103 | 3 | 1 | 1 |

## FCFS

  Examine the class scheduling with The algorithm FCFS (First in First Serve) has the same definition as FIFO (First in First out), where the front line is first served. Different from priority (SJF) or first named Shortest work, which serves the shortest period of jobs.

### Output:

Order in which processes gets executed
| Course Code | Duration | Waiting Time | Turnaround Time |
| :---------------: | :---------------: | :---------------: | :----------------: |
| 2201 | 3 | 0 | 3 |
| 3401 | 2 | 3 | 5 |
| 1103 | 1 | 5 | 6 |

Average waiting time = 2.67

Average turn around time = 4.67

## SJF

  Using SJF algorithm that performed in Non-Preemptive scheduling, The CPU does not require processes in the ready queue to move the processes being executed by the CPU even if there is a smaller burst time for the new operation.

### Output:

Order in which processes gets executed
| Course Code | Duration | Waiting Time | Turnaround Time |
| :---------------: | :---------------: | :---------------: | :----------------: |
| 2201 | 3 | 0 | 3 |
| 3401 | 2 | 3 | 5 |
| 1103 | 1 | 1 | 2 |

Average waiting time = 1.33

Average turn around time = 3.33

## Priority Scheduling

  Priority Scheduling is a programming algorithm that prioritizes the highest priority process. Every single method has its own priority. Priority scheduling can be performed either preventively or non-preventively. On non-preemptive, newly arrived processes it is not possible to interact with operating processes, but only to place them in queue.

### Output:

Order in which processes gets executed
| Course Code | Duration | Waiting Time | Turnaround Time |
| :---------------: | :---------------: | :---------------: | :----------------: |
| 1103 | 1 | 5 | 6 |
| 2201 | 3 | 2 | 5 |
| 3401 | 2 | 0 | 2 |

Average waiting time = 1.67

Average turn around time = 3.67

# Conclusion
  In summary, the class scheduling that was given show up the different result of average waiting time  for each kind of algorithm we use. 
