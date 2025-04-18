
# 💾 Part 2 – Memory Management: Page Replacement Algorithms

### 📌 Operating System Design Project – Fall 2024 | University of North Texas  
🧑‍🏫 Instructor: Prof. Amar M. Maharjan  
📁 Project 5 of 6 | Focus: Page Replacement Strategy Simulation & Evaluation

This project simulates and evaluates five popular page replacement algorithms to understand their efficiency in managing memory pages. Each algorithm is tested using reference strings from input files and frame sizes of 10 and 20. The results are analyzed based on the number of page faults encountered during execution.

---

## 🧠 Algorithms Implemented

1. **FIFO (First-In First-Out)** – Replaces the oldest page in memory.
2. **Optimal** – Replaces the page that will not be used for the longest future duration.
3. **LRU (Least Recently Used)** – Removes the least recently accessed page.
4. **LFU (Least Frequently Used)** – Evicts the page with the lowest access frequency.
5. **MFU (Most Frequently Used)** – Replaces the most frequently used page, assuming it's no longer needed.

Each algorithm is implemented in a separate C++ source file and handles custom reference string input formats.

---

## 📂 Folder Structure

```
Part2/
├── code/
│   ├── fifo.cpp
│   ├── optimal.cpp
│   ├── lru.cpp
│   ├── lfu.cpp
│   ├── mfu.cpp
│   └── input/                       # Reference strings for testing
├── docs/
│   └── Project2Report.docx
└── README.md                        # This file
```

---

## 📄 Input Format

Each line in the input file is a space-separated sequence of page references:

```
7 0 1 2 0 3 0 4 2 3 0 3 2
```

Files are grouped by test size (10-frame and 20-frame scenarios).

---

## ▶️ How to Compile and Run

Example for FIFO:
```bash
g++ fifo.cpp -o fifo
./fifo input/ref10_1.txt input/ref10_2.txt ...
```

Repeat similarly for other algorithm files.

---

## 📊 Results Summary (Page Faults)

| Algorithm | Avg Faults (10 Frames) | Avg Faults (20 Frames) |
|-----------|------------------------|-------------------------|
| FIFO      | 10.2                   | 25.6                    |
| Optimal   | 9.6                    | 21.8                    |
| LRU       | 10.0                   | 23.4                    |
| LFU       | 10.4                   | 23.4                    |
| MFU       | 10.2                   | 25.6                    |

📌 **Observation:** Optimal yields the lowest page faults as expected, while LFU and LRU provide efficient real-world alternatives.

---

## 📄 Documentation

Comprehensive explanations, charts, and comparisons are available in the DOCX report.

---

## 🧑‍💻 Contributors

- Ganesh Gundekarla  
- Shreya Sri Bearelly  
- Divya Sree Dandu  
- Vikas Varala  

---

## 📘 References

- Operating System Concepts, Silberschatz, Galvin & Gagne (10th Edition)
- Research on Memory Hierarchies and Caching Policies
