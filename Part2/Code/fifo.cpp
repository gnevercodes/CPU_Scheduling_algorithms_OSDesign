#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

//FIFO implementation
int ffPR(const vector<int>& rStr, int fC) { //rstr as referenceString, fC as frameCount
    unordered_set<int> fam;    //frames as fam, pagesQueue as pgQ
    queue<int> pgQ;        // To maintain the fifo order
    int pgF = 0; //pageFaults as pgF

    for (int pg : rStr) { //page as pg
        
        if (fam.find(pg) == fam.end()) {
            
            pgF++;

            // If memory is full, remove the oldest page
            if (fam.size() == fC) {
                int oldPG = pgQ.front();
                pgQ.pop();
                fam.erase(oldPG);
            }

            // Add the new page to memory and the queue
            fam.insert(pg);
            pgQ.push(pg);
        }
    }

    return pgF;
}


void pTC(const string& fileName) { //pTC as processTestCase
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }

    string line;
    vector<int> rStr;
    int fC = 0;

    while (getline(file, line)) {
        if (line.find("Reference String:") != string::npos) {
            // Extract reference string
            stringstream ss(line.substr(line.find(":") + 1));
            int pg;
            while (ss >> pg) {
                rStr.push_back(pg);
                if (ss.peek() == ',') ss.ignore();
            }
        } else if (line.find("Frame Count:") != string::npos) {
            // Extract frame count
            fC = stoi(line.substr(line.find(":") + 1));
        }
}
    file.close();

  
    int totlPgF = ffPR(rStr, fC);

    
    cout << "File: " << fileName << endl;
    cout << "Reference String: ";
    for (int pg : rStr) cout << pg << " ";
    cout << "\nFrame Count: " << fC << endl;
    cout << "Total Page Faults: " << totlPgF << "\n" << endl;
}

int main(int argc, char *argv[]) {
   
    if (argc < 2) {
        cerr << "Usage: " << argv[0] 
             << " <referenceString1.txt> <referenceString2.txt> <referenceString3.txt> "
             << "<referenceString4.txt> <referenceString5.txt> <referenceString6.txt> "
             << "<referenceString7.txt> <referenceString8.txt> <referenceString9.txt> "
             << "<referenceString10.txt>" << endl;
        return 1;
    }

    
    for (int i = 1; i < argc; ++i) {
        pTC(argv[i]);
    }

    return 0;
}
