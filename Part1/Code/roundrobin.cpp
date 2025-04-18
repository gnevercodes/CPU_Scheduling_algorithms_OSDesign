#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <queue>

struct Proceed {
    std::string val;
    int precedence; // priority
    int bClock;     // burst time
    int rClock; // remaining burst time
    int wClock;     // waiting time
    int tClock;     // turnaround time
};

void disTskFromFile(const std::string &filename, std::vector<Proceed> &proceeding) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string val;
        int precedence, bClock;
        while (file >> val >> precedence >> bClock) {
            proceeding.push_back({val, precedence, bClock, bClock, 0, 0});
        }
        file.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

void rRobscheduling(std::vector<Proceed> &proceeding, int cQuant) {  // Round robin scheduling where cQuant is time quantum
    std::queue<Proceed*> q;
    int clock = 0; //clock as in time

    for (auto &proc : proceeding) {
        q.push(&proc);
    }

    while (!q.empty()) {
        Proceed* curval = q.front(); //curval as in current
        q.pop();

        if (curval->rClock > cQuant) {
            clock += cQuant;
            curval->rClock -= cQuant;
            q.push(curval); // Push back into the queue
        } else {
            clock += curval->rClock;
            curval->wClock = clock - curval->bClock; // Calculate waiting time
            curval->tClock = clock; // Turnaround time
            curval->rClock = 0; // Task finished
        }
    }
}

double calAvgWClock(const std::vector<Proceed> &proceeding) {
    int tHaultClock = 0; // total waiting time
    for (const auto &proc : proceeding) {
        tHaultClock += proc.wClock;
    }
    return static_cast<double>(tHaultClock) / proceeding.size();
}

void disTsk(const std::vector<Proceed> &proceeding) {
    std::cout << "Process\tPriority\tBurst Time\tWait Time\tTurnaround Time\n";
    for (const auto &proc : proceeding) {
        std::cout << proc.val << "\t" << proc.precedence << "\t\t" << proc.bClock 
                  << "\t\t" << proc.wClock << "\t\t" << proc.tClock << "\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << "<scheduleEx.txt> <schedule6Ex1.txt> <schedule6Ex2.txt> <schedule6Ex3.txt> <schedule6Ex4.txt> <schedule6Ex5.txt> <schedule10Ex1.txt> <schedule10Ex2.txt> <schedule10Ex3.txt> <schedule10Ex4.txt> <schedule10Ex5.txt> <schedule16Ex1.txt> <schedule16Ex2.txt> <schedule16Ex3.txt> <schedule16Ex4.txt> <schedule16Ex5.txt" << std::endl;
        return 1;
    }

    const int cQuant = 10; // Time quantum 
    for (int i = 1; i < argc; ++i) {
        std::vector<Proceed> proceeding;
        disTskFromFile(argv[i], proceeding);
        rRobscheduling(proceeding, cQuant);
        disTsk(proceeding);
        double medianHaultClock = calAvgWClock(proceeding); //average waiting time
        std::cout << "\nAverage Waiting Time of Round Robin Algorithm is: " << std::fixed 
                  << std::setprecision(2) << medianHaultClock << "\n\n";
    }

    return 0;
}
