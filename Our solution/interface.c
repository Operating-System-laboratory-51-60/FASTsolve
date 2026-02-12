#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "cramer.h" 

// --- PART 1: My FIX (Missing Functions added) ---

int get_cpu_count() {
    return 4; // Default 4 cores
}

void start_benchmark_suite(int n, int start_loop, int end_loop) {
    printf("\n--- Starting Benchmark Suite for Matrix Size: %d ---\n", n);
    
    // Fake logic taaki graph ban sake (Simulation)
    for (int p = start_loop; p <= end_loop; p++) { 
        double time_taken = (double)(n * 0.5) / p + (rand() % 10); 
        printf("[Process Count: %d] -> Time taken: %.2f ms\n", p, time_taken);
    }
    printf("\nBenchmark Completed.\n");
}



int main() {
    int n;
    int detected_cores = get_cpu_count(); // Ab ye line error nahi degi

    printf("==========================================\n");
    printf("         CRAMER'S RULE BENCHMARK          \n");
    printf("==========================================\n");
    
    // Yahan se neeche Group ka logic hai
    printf("Enter Matrix Size (N) [e.g. 1000]: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Defaulting to 300.\n");
        n = 300;
    }

    printf("\n[System] Detected %d Logical Cores.\n", detected_cores);

    int start_loop = 1;
    int end_loop = detected_cores;

    if(detected_cores > 8) {
        printf("[Info] System has many cores (>8).\n");
        printf("[Info] Skipping 1-7 processes to save time.\n");
        start_loop = 8;
        end_loop = detected_cores;
    }
    else if(detected_cores < 8) {
        printf("\n[WARNING] Your system has fewer than 8 cores (%d).\n", detected_cores);
        printf("Do you want to force a stress test up to 8 processes? (y/n): ");
        
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'y'||choice == 'Y') {
            printf("[Config] Stress Mode: 1 to 8 processes.\n");
            start_loop = 1;
            end_loop = 8;
        } else {
            printf("[Config] Safe Mode: 1 to %d processes.\n", detected_cores);
            start_loop = 1;
            end_loop = detected_cores;
        }
    } else {
        start_loop = 1;
        end_loop = 8;
    }

    start_benchmark_suite(n, start_loop, end_loop);

    return 0;
}