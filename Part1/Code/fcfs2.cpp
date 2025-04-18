#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Proceed { //Process
    std::string value;
    int precedence; //priority
    int bClock; //burstTime
    int wClock; //waitTime
    int tClock; //turnaroundTime
};

std::vector<Proceed> readProceeding(const std::string &inputname) {
    std::ifstream file(inputname);
    std::vector<Proceed> proceeding; //processes
    std::string value;
    int precedence, bClock;

    // you are checking if the file is succesfully opened 
    if (!file) {
        std::cerr << "Failed to open the file: " << inputname << std::endl;
        return proceeding; // If the file is absent return with the failure message
    }

    while (file >> value >> precedence >> bClock) {
        proceeding.push_back({value, precedence, bClock, 0, 0});
    }
    return proceeding;
}

void fcfs(std::vector<Proceed> &proceeding) {
    int cClock = 0; //currentTime
    for (auto &p : proceeding) {
        p.wClock = cClock;
        p.tClock = cClock + p.bClock;
        cClock += p.bClock;
    }
}

void showAnswer(const std::vector<Proceed> &proceeding) {
    std::cout << "Process\tpriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
    int tHaultClock = 0; //totalWaitingTime

    for (const auto &q : proceeding) {
        std::cout << q.value << "\t" << q.precedence << "\t\t" << q.bClock
                  << "\t\t" << q.wClock << "\t\t" << q.tClock << "\n";
        tHaultClock += q.wClock; // pile up total waiting time
    }

    // From above value calcualte median of the waiting time and display the results
    double medianHaultClock = static_cast<double>(tHaultClock) / proceeding.size(); //averageWaitingTime
    std::cout << std::fixed << std::setprecision(3); // give decimal precision upto  3 valuws
    std::cout << "The Average Waiting Time of fcfs is: " << medianHaultClock << "\n";
}

int main(int argc, char *argv[]) {
    std::vector<Proceed> proceeding;

    // check if it satisfies the filename given in the output to show the result
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << "<scheduleEX,txt> <schedule6Ex1.txt> <schedule6Ex2.txt> <schedule6Ex3.txt> <schedule6Ex4.txt> <schedule6Ex5.txt> <schedule10Ex1.txt> <schedule10Ex2.txt> <schedule10Ex3.txt> <schedule10Ex4.txt> <schedule10Ex5.txt> <schedule16Ex1.txt> <schedule16Ex2.txt> <schedule16Ex3.txt> <schedule16Ex4.txt> <schedule16Ex5.txt>" << std::endl;
        return 1;
    }

    // Read processes from each provided file
    for (int i = 1; i < argc; ++i) {
        std::vector<Proceed> tempProceeding = readProceeding(argv[i]);
        proceeding.insert(proceeding.end(), tempProceeding.begin(), tempProceeding.end());
    }

    // Perform FCFS scheduling
    fcfs(proceeding);
    // give the output
    showAnswer(proceeding);
    
    return 0;
}
