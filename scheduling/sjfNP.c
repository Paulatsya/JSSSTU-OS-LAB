#include <stdio.h>
typedef struct
{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int rt;
    int finished;
} Process;
void sjfNP(Process p[], int n);
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("burst time: ");
        scanf("%d", &p[i].bt);
        printf("\n");
    } // for(takes process values)
    sjfNP(p, n);
    return 0;
}
void sjfNP(Process p[], int n)
{
    float avgRT = 0, avgWT = 0, avgTT = 0;
    int totalRT = 0, totalWT = 0, totalTT = 0;
    int exec;
    int et = 0;
    int remaining = n;
    while (remaining)
    {
        exec = -1;
        int shortest = 9999;
        for (int i = 0; i < n; i++)
        {
            if (!p[i].finished && p[i].at <= et)
            {
                if (p[i].bt < shortest)
                {
                    exec = i;
                    shortest = p[i].bt;
                }
            }
        }
        if (exec == -1)
        {
            printf("|(%d)***(%d)|", et, et + 1);
            et++;
        }
        else
        {
            int temp = et;
            et += p[exec].bt;
            p[exec].rt = temp - p[exec].at;
            p[exec].finished = 1;
            p[exec].ct = et;
            p[exec].tt = p[exec].ct - p[exec].at;
            p[exec].wt = p[exec].tt - p[exec].bt;
            remaining--;
            printf("|(%d) P%d (%d)", temp, p[exec].pid, et);
        }
    }
    printf("|\n");
    printf("||| Observation table |||\n");
    printf("pID\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt, p[i].rt);
        totalWT += p[i].wt;
        totalRT += p[i].rt;
        totalTT += p[i].tt;
    }
    printf("\nAvgWT= %.2f", (float)totalWT / n);
    printf("\nAvgTT= %.2f", (float)totalTT / n);
    printf("\nAvgRT= %.2f", (float)totalRT / n);
}