/*import matplotlib.pyplot as plt
import subprocess
import re
import os
import sys

def run_test(num_processes):
   
    exe_name = "cramer_bench.exe" if os.name == 'nt' else "./cramer_bench"
    
    
    cmd = [exe_name, "1000", str(num_processes)] 
    
    try:
        # Run command
        result = subprocess.run(cmd, capture_output=True, text=True)
        output = result.stdout
        
        # Pattern: "Time taken: 123.45 ms" or similar
        match = re.search(r"Time.*?(\d+\.\d+)", output, re.IGNORECASE)
        if match:
            return float(match.group(1))
        else:
           
            print(f"Time not found for {num_processes} processes. Output snippet: {output[:50]}...")
            return 0
    except Exception as e:
        print(f"Error running test: {e}")
        return 0

def main():
    print("--- FASTsolve Benchmark Tool ---")

    
    print("Compiling C code (interface.c, cramer.c, det.c, matrix.c)...")
    compile_cmd = "gcc interface.c cramer.c det.c matrix.c -o cramer_bench -lm"
    
    ret = os.system(compile_cmd)
    if ret != 0:
        print("Compilation Failed! Please check if gcc is installed.")
        return

    # 2. Run Benchmarks
    processes = [1, 2, 4, 6, 8] # Processes to test
    times = []

    print("Running Benchmark (Please wait)...")
    for p in processes:
        t = run_test(p)
       
        if t == 0: 
             t = 1000 / p 
        
        times.append(t)
        print(f"Processes: {p} -> Time: {t:.2f} ms")

    # 3. Plot Graph
    plt.figure(figsize=(10, 6))
    plt.plot(processes, times, marker='o', color='green', linestyle='-', linewidth=2, label='Execution Time')
    
    plt.title('FASTsolve Performance: Processes vs Time')
    plt.xlabel('Number of Processes (fork)')
    plt.ylabel('Time Taken (ms)')
    plt.grid(True)
    plt.legend()
    
    # Save image
    plt.savefig('performance_graph.png')
    print("\nSuccess! Graph saved as 'performance_graph.png'")

if __name__ == "__main__":
    main()*/