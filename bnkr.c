#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int cur[5][5];
    int claim[5][5];
    int avail[5];
    int allocs[5] = {0, 0, 0, 0, 0};
    int res[5];
    int running[5];
 
    int i, j, exec, r, p;
    int counter = 0;
    bool safe = false;
 
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);
 
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        running[i] = 1;
        counter++;
    }
 
    printf("\nEnter Claim Vector: ");
    for (i = 0; i < r; i++)
        scanf("%d", &res[i]);
 
    printf("\nEnter Allocated Resource Table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &cur[i][j]);
    }
 
    printf("\nEnter Maximum Claim table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &claim[i][j]);
    }
 
    printf("\nThe Claim Vector is: ");
    for (i = 0; i < r; i++)
        printf("%d ",res[i]);
 
    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", cur[i][j]);
        printf("\n");
    }
 
    printf("\nThe Maximum Claim Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", claim[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += cur[i][j];
 
    printf("\nAllocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);
    for (i = 0; i < r; i++)
        avail[i] = res[i] - alloc[i];
 
    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avail[i]);
    printf("\n");
 
    while (counter != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (claim[i][j] - cur[i][j] > avail[j]) {
                        exec = 0;
                        break;
                    }
                }
 
                if (exec) {
                    printf("\nProcess%d is executing.\n", i + 1);
                    running[i] = 0;
                    counter--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avail[j] += cur[i][j];
                    break;
                }
            }
        }
 
        if (!safe) {
            printf("\nThe processes are in unsafe state.");
            break;
        }
 
        if (safe)
            printf("\nThe process is in safe state.");
 
        printf("\nAvailable vector: ");
        for (i = 0; i < r; i++)
            printf("%d ", avail[i]);
    }
 
    return 0;
}