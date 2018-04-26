# Matrix-Multiplier
This project focuses on how to use “parallel for” and optimize a matrix-matrix multiplication to gain better performance.
C++ and OpenMP library will be used.

# Tasks
- Sequential matrix-matrix multiplication.
- Parallel matrix-matrix multiplication using a “parallel for” loop.
- Optimized parallel matrix-matrix multiplication according to the cpu architecture.
- Analyse execution times
>Note: Only the time spent for matrix multiplication is calculated

# Instruction to Compile and Execute this program
## Step 1 - Prerequisites
Open the command prompt or the terminal in the project folder.
Windows users, make sure to have a C/C++ compiler like MinGW or TDM-GCC installed in the machine, and proper environment variables set.

## Step 2 - Compile
Run the following command to compile the application.
Make sure to include openmp using ```-fopenmp``` and make sure to enable c++11 features using ```-std=c++11``` options.

##### Sequential implementation
```bash
g++ src/sequential.cpp src/matrix.cpp src/util.cpp -o sequential -fopenmp -std=c++11
```

##### Parallel implementation
```bash
g++ src/parallel.cpp src/matrix.cpp src/util.cpp -o parallel -fopenmp -std=c++11
```

##### Optimized implementation
```bash
g++ src/optimized.cpp src/matrix.cpp src/util.cpp -o optimized -O2 -fopenmp -std=c++11
```
>Note: Since the implementation use the features enabled by the O2 optimization and use that to gain additional performance as described in the report, when compiling the optimized version use O2 optimization by adding the '-O2' flag.

## Step 3 - Run
Above command will create a executable file in the same directory.
Double click and open it (windows)
Or execute following command in the terminal (linux)
```bash
./<file_name>
```

## Step 4 - Program arguments
Every execution has two modes.
1. Single execution - Execute for single matrix size
2. Batch mode - Execute for 200, 400, 600, 800 upto 2000

Each mode ask for number of sample size that the code need to run and then get the average execution time, standant deviation and needed sample size.