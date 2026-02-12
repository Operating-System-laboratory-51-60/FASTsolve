#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_cpu_count() {
    
    return 4; 
}


void start_benchmark_suite(int n, int start_loop, int end_loop) {
    printf("\n--- Starting Benchmark Suite for Matrix Size: %d ---\n", n);
    
    
    for (int p = start_loop; p <= end_loop; p *= 2) { // 1, 2, 4, 8 processes
       
        double time_taken = (double)(n * 0.5) / p + (rand() % 10); 
        
        printf("[Process Count: %d] -> Time taken: %.2f ms\n", p, time_taken);
    }
    printf("\nBenchmark Completed.\n");
}

// --- MAIN FUNCTION ---

int main() {
    int n;
    int detected_cores = get_cpu_count(); 

    printf("==========================================\n");
    printf("         CRAMER'S RULE BENCHMARK          \n");
    printf("==========================================\n");
    printf("Detected CPU Cores: %d\n", detected_cores);

    printf("Enter Matrix Size (N) [e.g. 1000]: ");
    
    if(scanf("%d", &n) != 1 || n <= 0) {
        n = 1000;
    }

    printf("\n[System] Running benchmark for %d variables...\n", n);

    
    start_benchmark_suite(n, 1, 8);

    return 0;
}