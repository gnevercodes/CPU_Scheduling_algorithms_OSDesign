#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Proceed {  //Process
    std::string val;
    int precedence; //priority
    int bClock; //burstTime
    int wClock; //waitingTime
    int tClock; //turnaroundTime
};

bool compareByPrecedence(const Proceed &g, const Proceed &h) {
    return g.precedence > h.precedence; // Higher priority tasks first
}

void calClock(std::vector<Proceed> &proceeding) { //Caclulate the time
    proceeding[0].wClock = 0;
    proceeding[0].tClock = proceeding[0].bClock;
    
    for (size_t k = 1; k < proceeding.size(); k++) {
        proceeding[k].wClock = proceeding[k - 1].wClock + proceeding[k - 1].bClock;
        proceeding[k].tClock = proceeding[k].wClock + proceeding[k].bClock;
    }
}

double calAvgWClock(const std::vector<Proceed> &proceeding) { // Calculate average waiting time
    int tHaultClock = 0; //totalWaitingTime
    for (const auto &proceed : proceeding) {
        tHaultClock += proceed.wClock;
    }
    return static_cast<double>(tHaultClock) / proceeding.size();
}

void disTskFromFile(const std::string &filename, std::vector<Proceed> &proceeding) { // Now load the tasks from file
    std::ifstream file(filename);
    if (file.is_open()) { // Check if the file is present or not
        std::string val;
        int precedence, bClock;
        while (file >> val >> precedence >> bClock) {
            proceeding.push_back({val, precedence, bClock, 0, 0});
        }
        file.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

void disTsk(const std::vector<Proceed> &proceeding) { // Displaying the results in the output
    std::cout << "Process\tPriority\tBurst Time\tWait Time\tTurnaround Time\n";
    for (const auto &proceed : proceeding) {
        std::cout << proceed.val << "\t" << proceed.precedence << "\t\t" << proceed.bClock << "\t\t" << proceed.wClock << "\t\t" << proceed.tClock << "\n";
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << "<scheduleEx.txt> <schedule6Ex1.txt> <schedule6Ex2.txt> <schedule6Ex3.txt> <schedule6Ex4.txt> <schedule6Ex5.txt> <schedule10Ex1.txt> <schedule10Ex2.txt> <schedule10Ex3.txt> <schedule10Ex4.txt> <schedule10Ex5.txt> <schedule16Ex1.txt> <schedule16Ex2.txt> <schedule16Ex3.txt> <schedule16Ex4.txt> <schedule16Ex5.txt" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<Proceed> proceeding;

    disTskFromFile(filename, proceeding);
    std::sort(proceeding.begin(), proceeding.end(), compareByPrecedence);

    calClock(proceeding);
    double medianHaultClock = calAvgWClock(proceeding); //average Waiting Time
    disTsk(proceeding);
    std::cout << "\nAverage Waiting Time of Priority algorithm is: " << std::fixed << std::setprecision(2) << medianHaultClock << "\n";

    return 0;
}
