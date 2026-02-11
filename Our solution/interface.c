#include <stdio.h>
#include <stdlib.h>
#include "cramer.h"

int main() {
    int n;
    int detected_cores = get_cpu_count();

    printf("==========================================\n");
    printf("         CRAMER'S RULE BENCHMARK          \n");
    printf("==========================================\n");
    
    printf("Enter Matrix Size (N) [e.g. 1000]: ");
    if(scanf("%d", &n) != 1||n <= 0)
    {
        printf("Invalid size. Defaulting to 300.\n");
        n = 300;
    }

    printf("\n[System] Detected %d Logical Cores.\n", detected_cores);

    int start_loop = 1;
    int end_loop = detected_cores;

    if(detected_cores > 8)
    {
        printf("[Info] System has many cores (>8).\n");
        printf("[Info] Skipping 1-7 processes to save time.\n");
        start_loop = 8;
        end_loop = detected_cores;
    }
    else if(detected_cores < 8)
    {
        printf("\n[WARNING] Your system has fewer than 8 cores (%d).\n", detected_cores);
        printf("Do you want to force a stress test up to 8 processes? (y/n): ");
        
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'y'||choice == 'Y')
        {
            printf("[Config] Stress Mode: 1 to 8 processes.\n");
            start_loop = 1;
            end_loop = 8;
        }
        else
        {
            printf("[Config] Safe Mode: 1 to %d processes.\n", detected_cores);
            start_loop = 1;
            end_loop = detected_cores;
        }
    }
    else
    {
        start_loop = 1;
        end_loop = 8;
    }

    start_benchmark_suite(n,start_loop,end_loop);

    return 0;
}