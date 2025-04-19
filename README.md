
# 🧠 Operating System Design – Academic Project (Fall 2024)

## 🎓 CSCE 5640 – University of North Texas  
**Instructor:** Prof. Amar M. Maharjan  
**Team Members:** Ganesh Gundekarla, Shreya Sri Bearelly, Divya Sree Dandu, Vikas Varala  

This repository contains a two-part academic project on **Operating System Design**, focused on process scheduling and memory management. Each part covers core operating system concepts implemented in C++, tested with real scenarios, and analyzed with custom-built datasets. This project is part of a six-project academic portfolio developed during graduate coursework.

---

## 📁 Repository Structure

```
os-design-project/
├── Part1/                         # CPU Scheduling Algorithms
│   ├── code/
│   ├── docs/
│   └── README.md
├── Part2/                         # Page Replacement Algorithms
│   ├── code/
│   ├── docs/
│   └── README.md
└── README.md                      # (This file) Combined Overview
```

---

## ⚙️ Part 1 – CPU Scheduling Algorithms

### 🧠 Overview
Implements and evaluates five core CPU scheduling strategies:  
- First-Come First-Served (FCFS)  
- Shortest Job First (SJF)  
- Priority Scheduling  
- Round Robin  
- Priority with Round Robin  

Each algorithm is tested on custom datasets containing 6, 10, and 16 processes. Results focus on metrics like average waiting time and turnaround time. Outputs are generated and analyzed using Python visualization tools.

---

## 💾 Part 2 – Page Replacement Algorithms

### 🧠 Overview
Simulates five page replacement strategies:  
- FIFO  
- Optimal  
- LRU (Least Recently Used)  
- LFU (Least Frequently Used)  
- MFU (Most Frequently Used)  

Each algorithm is tested with reference strings and evaluated using different frame sizes (10 and 20). The analysis focuses on the number of page faults and efficiency of real-time memory handling strategies.

---

## 📈 Summary Tables

### CPU Scheduling – Avg Waiting Time

| Algorithm               | 6 Procs | 10 Procs | 16 Procs |
|------------------------|---------|----------|----------|
| FCFS                   | 44.17   | 83.24    | 136.26   |
| SJF                    | 32.67   | 65.88    | 109.49   |
| Priority               | 50.20   | 81.66    | 138.10   |
| Round Robin            | 58.20   | 121.50   | 200.71   |
| Priority + Round Robin | 50.73   | 82.44    | 138.16   |

### Page Replacement – Avg Page Faults

| Algorithm | 10 Frames | 20 Frames |
|-----------|-----------|-----------|
| FIFO      | 10.2      | 25.6      |
| Optimal   | 9.6       | 21.8      |
| LRU       | 10.0      | 23.4      |
| LFU       | 10.4      | 23.4      |
| MFU       | 10.2      | 25.6      |

---

## 🧾 Learning Outcomes

- Gained hands-on experience simulating low-level OS mechanisms
- Understood how CPU and memory scheduling impacts performance
- Practiced software modularity, input handling, and evaluation pipelines . 
- Leveraged C++ for systems programming and Python for analysis and executed those in linux and google colab. 

---

## 📫 Contact

Created by Ganesh Gundekarla  
🔗 [LinkedIn](https://www.linkedin.com/in/ganeshgundekarla) • [GitHub](https://github.com/gnevercodes)
