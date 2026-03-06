#include <stdio.h>
struct Process {
    int pid;        // Process ID
    int at;         // Arrival Time
    int bt;         // Burst Time
    int ct;         // Completion Time
    int tat;        // Turnaround Time
    int wt;         // Waiting Time
    int rt;         // Response Time
};
int main() {
    int n = 4;
    struct Process p[4];
    int i, time = 0;
    int arrival[] = {0, 8, 3, 5};
    int burst[]   = {7, 3, 4, 6};
    for (i = 0; i < n; i++) {
        p[i].pid = i+1;
        p[i].at = arrival[i];
        p[i].bt = burst[i];
    }
    for (i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    time = 0;
    for (i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at;
        }
        p[i].rt = time - p[i].at;
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    return 0;
}
