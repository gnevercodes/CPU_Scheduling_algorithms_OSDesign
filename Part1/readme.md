
#  Part 1 – CPU Scheduling Algorithms

### 📌 Operating System Design Project – Fall 2024 | University of North Texas  
🧑‍🏫 Instructor: Prof. Amar M. Maharjan  
📁 Project 5 of 6 | Focus: CPU Scheduling Strategy Implementation & Evaluation

This project simulates five classical CPU scheduling algorithms using C++ to understand their behavior in handling process execution. The algorithms are tested using 15 input files containing process details such as burst time and priority, simulating workloads with 6, 10, and 16 processes.

---

## 🧠 Algorithms Implemented

1. **FCFS (First-Come First-Served)** – Non-preemptive, executes processes in arrival order.
2. **SJF (Shortest Job First)** – Non-preemptive, selects the shortest burst time first.
3. **Priority Scheduling** – Non-preemptive, executes processes based on assigned priority.
4. **Round Robin (RR)** – Preemptive, time-sharing model with a defined time quantum.
5. **Priority + Round Robin** – Hybrid: processes are ordered by priority and executed using RR among equal-priority tasks.

Each algorithm is implemented in its own C++ source file located in the `code/` directory.

---

## 📂 Folder Structure

```
Part1/
├── code/
│   ├── fcfs.cpp
│   ├── sjf.cpp
│   ├── priority.cpp
│   ├── rr.cpp
│   ├── priority_rr.cpp
│   └── input/                          # All 15 test input files
├── docs/
│   └── Project_Report_OSD_part1.pdf
└── README.md                          # This file
```

---

## 🧪 Input Format

Each line in the input file represents a process with 3 space-separated values:

```
<ProcessID> <Priority> <BurstTime>
```

Example:
```
P1 2 10
P2 1 4
P3 3 5
```

---

## ▶️ How to Compile and Run

Compile the desired algorithm file:

```bash
g++ fcfs.cpp -o fcfs
./fcfs input/schedule6Ex1.txt input/schedule10Ex1.txt ...
```

Replace `fcfs.cpp` with any other algorithm file (`sjf.cpp`, `priority.cpp`, etc.) as needed.

---

## 📊 Results Summary (Average Waiting Time)

| Algorithm               | 6 Procs | 10 Procs | 16 Procs |
|------------------------|---------|----------|----------|
| FCFS                   | 44.17   | 83.24    | 136.26   |
| SJF                    | 32.67   | 65.88    | 109.49   |
| Priority               | 50.20   | 81.66    | 138.10   |
| Round Robin            | 58.20   | 121.50   | 200.71   |
| Priority + Round Robin | 50.73   | 82.44    | 138.16   |

📌 **Observation:** SJF consistently results in the least average wait time across all input sizes.

---

## 📄 Documentation

Detailed analysis, graphs, and evaluation insights are available in the PDF report.

---

## 🧑‍💻 Contributors ( each contributed majorly in this project) 

- Ganesh Gundekarla  
- Shreya Sri Bearelly  
- Divya Sree Dandu  
- Vikas Varala  

---

## 🧠 References

- Operating System Concepts, Silberschatz, Galvin & Gagne (10th Edition)
- IEEE Research Papers on Scheduling Efficiency & Heuristics

