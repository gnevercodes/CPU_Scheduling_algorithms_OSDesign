#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[20];
    int precedence; // priority
    int bClock;     // burstTime
    int wClock;     // waitingTime
    int tClock;     // turnaroundTime
} Proceed; // Process

int readProceeding(Proceed *proceeding, const char *inputname) {
    FILE *file = fopen(inputname, "r");
    int count = 0;

    if (file == NULL) {
        printf("Failed to open the file: %s\n", inputname);
        return 0;
    }

    while (fscanf(file, "%s %d %d", proceeding[count].id, &proceeding[count].precedence, &proceeding[count].bClock) != EOF) {
        proceeding[count].wClock = 0;
        proceeding[count].tClock = 0;
        count++;
    }

    fclose(file);
    return count;
}

void calculateSJF(Proceed *proceeding, int n) {
    Proceed sorted[n];
    memcpy(sorted, proceeding, n * sizeof(Proceed)); // Copy original array to maintain order
    
    // Sort the copied array by burst time in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sorted[i].bClock > sorted[j].bClock) {
                Proceed temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // Calculate waiting and turnaround times in sorted order
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        sorted[i].wClock = currentTime;
        sorted[i].tClock = sorted[i].wClock + sorted[i].bClock;
        currentTime += sorted[i].bClock;
    }

    // Update waiting and turnaround times in the original order
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(proceeding[i].id, sorted[j].id) == 0) {
                proceeding[i].wClock = sorted[j].wClock;
                proceeding[i].tClock = sorted[j].tClock;
                break;
            }
        }
    }
}

void showAnswer(const Proceed *proceeding, int n) {
    int totalWaitingTime = 0;
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", proceeding[i].id, proceeding[i].precedence, proceeding[i].bClock, proceeding[i].wClock, proceeding[i].tClock);
        totalWaitingTime += proceeding[i].wClock;
    }

    printf("\nAverage Waiting Time of sjf algorithm is: %.2f\n", (float)totalWaitingTime / n);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <scheduleEx.txt> <schedule6Ex1.txt> <schedule6Ex2.txt> <schedule6Ex3.txt> <schedule6Ex4.txt> <schedule6Ex5.txt> <schedule10Ex1.txt> <schedule10Ex2.txt> <schedule10Ex3.txt> <schedule10Ex4.txt> <schedule10Ex5.txt> <schedule16Ex1.txt> <schedule16Ex2.txt> <schedule16Ex3.txt> <schedule16Ex4.txt> <schedule16Ex5.txt\n", argv[0]);
        return 1;
    }

    Proceed proceeding[100];
    int proceedCount = readProceeding(proceeding, argv[1]);

    if (proceedCount > 0) {
        calculateSJF(proceeding, proceedCount);
        showAnswer(proceeding, proceedCount);
    } else {
        printf("No processes found in file.\n");
    }

    return 0;
}
