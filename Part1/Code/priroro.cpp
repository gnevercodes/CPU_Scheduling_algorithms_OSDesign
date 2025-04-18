#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

struct Task {
    std::string val;
    int precedence; // priority
    int bClock; // burst time
    int rClock; // remaining burst time
    int wClock; // waiting time
    int tClock; // turnaround time
};

void disTskFromFile(const char* filename, std::vector<Task>& tasks) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open the file. " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Task task;
        iss >> task.val >> task.precedence >> task.bClock;  // Read precedence before burst time
        task.rClock = task.bClock;  // Initialize remaining time as burst time
        task.wClock = 0;
        task.tClock = 0;
        tasks.push_back(task);
    }
    file.close();
}

void precedence_roundrobin(std::vector<Task>& tasks, int cQuant) { //
    std::map<int, std::queue<int>, std::greater<int>> precedence_queue_map;  // Map from precedence to a queue of task indices, sorted in descending order of precedence
    int curval = 0; // where curval is current_time
    int no_of_taskscmpltd = 0;
    int num_tasks = tasks.size();

    // intitially prioritizing tasks into precedence queues
    for (size_t i = 0; i < tasks.size(); i++) {
        precedence_queue_map[tasks[i].precedence].push(i);
    }

    while (no_of_taskscmpltd < num_tasks) {
        bool task_executed = false;

        // Since it is round robin iterating the priority in descending order (highest priority first)
        for (auto& entry : precedence_queue_map) {
            int precedence = entry.first;
            auto& task_queue = entry.second;

            if (task_queue.empty()) continue;

            int task_index = task_queue.front();
            task_queue.pop();
            Task& task = tasks[task_index];

            if (task.rClock > cQuant) {
                curval += cQuant;
                task.rClock -= cQuant;
                task_executed = true;
            } else {
                curval += task.rClock;
                task.rClock = 0;
                task.tClock = curval;
                task.wClock = task.tClock - task.bClock;
                no_of_taskscmpltd++;
                task_executed = true;
            }

            // calculating the tasks that are not complete
            if (task.rClock > 0) {
                task_queue.push(task_index);
            }

            if (task_executed) break;  // Moving for next time quant
        }

        // Incrementing time for next available task
        if (!task_executed) {
            curval++;
        }
    }
}

void pRoRoScheduling(const std::vector<Task>& tasks) {
    int total_wClock = 0;

    std::cout << "Process\tprecedence\tBurst Time\tWait Time\tTurnaround Time\n";
    for (const auto& task : tasks) {
        std::cout << task.val << "\t" 
                  << task.precedence << "\t\t" 
                  << task.bClock << "\t\t" 
                  << task.wClock << "\t\t" 
                  << task.tClock << "\n";
        total_wClock += task.wClock;
    }

    double avg_wClock = static_cast<double>(total_wClock) / tasks.size();
    std::cout << "Average Waiting Time: " << avg_wClock << std::endl; // find out average waiting time
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <scheduleEx.txt> <schedule6Ex1.txt> <schedule6Ex2.txt> <schedule6Ex3.txt> <schedule6Ex4.txt> <schedule6Ex5.txt> <schedule10Ex1.txt> <schedule10Ex2.txt> <schedule10Ex3.txt> <schedule10Ex4.txt> <schedule10Ex5.txt> <schedule16Ex1.txt> <schedule16Ex2.txt> <schedule16Ex3.txt> <schedule16Ex4.txt> <schedule16Ex5.txt" << std::endl;
        return 1;
    }

    const int cQuant = 10;  // Time quantum of 10 milliseconds
    std::vector<Task> tasks;
    disTskFromFile(argv[1], tasks);
    precedence_roundrobin(tasks, cQuant);
    pRoRoScheduling(tasks);

    return 0;
}