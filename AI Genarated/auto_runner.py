import os
import sys
import subprocess
import time

def main():
    print("[AI Runner] Compiling solution.c...")
    
    # Compile the C code
    compile_cmd = "gcc solution.c -o cramer_ai -lm"
    ret = os.system(compile_cmd)
    
    if ret != 0:
        print("[Error] Compilation failed.")
        sys.exit(1)
        
    print("[AI Runner] Compilation successful.")
    print("[AI Runner] Running Benchmark...")
    
    # Run the executable
    # Default to N=300 for quick test
    try:
        subprocess.run(["./cramer_ai", "300"], check=True)
    except KeyboardInterrupt:
        print("\n[AI Runner] Interrupted by user.")
    except Exception as e:
        print(f"[Error] Execution failed: {e}")

if __name__ == "__main__":
    main()
