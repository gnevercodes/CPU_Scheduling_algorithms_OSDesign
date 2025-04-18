
# 🧠 Operating System Design – Academic Project (Fall 2024)

## 🎓 CSCE 5640 – University of North Texas  
**Instructor:** Prof. Amar M. Maharjan  
**Team Members:** Ganesh Gundekarla, Shreya Sri Bearelly, Divya Sree Dandu, Vikas Varala  

This repository contains a two-part academic project focused on Operating System design, covering both CPU Scheduling and Page Replacement Algorithms. It is part of a 6-project academic portfolio and was developed as a capstone exercise to apply OS theory to real-world simulated environments using C++ and Linux.

---

## 📁 Project Structure
```
os-design-project/
├── part1_cpu_scheduling/        # CPU scheduling algorithms (FCFS, SJF, RR, etc.)
├── part2_memory_management/     # Page replacement algorithms (FIFO, LRU, Optimal, etc.)
└── README.md                    # Master README
```

---

## 🔹 Part 1 – CPU Scheduling Algorithms

### 🧠 Overview
Implements five core CPU scheduling algorithms: FCFS, SJF, Priority, Round Robin, and Priority with Round Robin. These were tested on datasets with 6, 10, and 16 processes to analyze wait time and turnaround time.

### 🛠️ Key Features
- Developed in C/C++ on Ubuntu
- Input test cases with varying workload sizes
- Output analysis includes average wait times and Gantt-like summaries
- Result graphs generated using Python (matplotlib, pandas)

📄 [Read Full Report – Part 1](part1_cpu_scheduling/docs/Project_Report_OSD_part1.pdf)

---

## 🔹 Part 2 – Page Replacement Algorithms

### 🧠 Overview
Analyzes memory management strategies through five page replacement algorithms: FIFO, Optimal, LRU (Second Chance), LFU, and MFU. This simulation evaluates page faults using artificial reference strings and frame sizes (10 and 20).

### 🛠️ Key Features
- Algorithms implemented in C++ and tested on Linux
- Handles custom input files containing reference strings
- Evaluates total page faults and page hits
- Visual comparisons of algorithm efficiency with graphs

📄 [Read Full Report – Part 2](part2_memory_management/docs/Project2Report.docx)

### 📊 Results Summary

| Algorithm | Avg Page Faults (10 frames) | Avg Page Faults (20 frames) |
|-----------|-----------------------------|------------------------------|
| FIFO      | 10.2                        | 25.6                         |
| Optimal   | 9.6                         | 21.8                         |
| LRU       | 10.0                        | 23.4                         |
| LFU       | 10.4                        | 23.4                         |
| MFU       | 10.2                        | 25.6                         |

---

## 🧾 Academic Objectives

- Apply theoretical concepts of CPU scheduling and memory paging in OS design
- Simulate practical scenarios with frame/process limitations
- Compare algorithm efficiency using statistical and visual tools
- Emphasize modular, readable, and testable code

---

## 📌 Future Work
- Extend simulations to support hybrid scheduling strategies
- Explore Clock and NRU algorithms for page replacement
- Introduce real-time dynamic reference string generation
- Evaluate algorithms in distributed and virtual memory environments

---

## 📫 Contact

Developed by Ganesh Gundekarla and team  
🔗 [LinkedIn](https://www.linkedin.com/in/ganeshgundekarla) • [GitHub](https://github.com/gnevercodes)
