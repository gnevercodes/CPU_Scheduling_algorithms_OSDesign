#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm> 
using namespace std;

// Optimal Pg Implementation
int optPR(const vector<int>& rStr, int fC) { //optimalPageReplacement as optPR, referenceString as rStr, frameCount as fC
    unordered_set<int> fam;                 
    int pgF = 0;

    for (int i = 0; i < rStr.size(); ++i) {
        int pg = rStr[i];

        
        if (fam.find(pg) == fam.end()) {
            
            pgF++;

            
            if (fam.size() == fC) {
                int pgTR = -1, extremeFar  = -1; //pageToReplace pgTR, Farthest as extremeFar 

                
                for (int f : fam) {
                    auto it = find(rStr.begin() + i + 1, rStr.end(), f);
                    int nxtUse = (it == rStr.end()) ? numeric_limits<int>::max() : distance(rStr.begin(), it);

                    if (nxtUse > extremeFar ) {
                        extremeFar  = nxtUse;
                        pgTR = f;
                    }
                }

              
                fam.erase(pgTR);
            }

            
            fam.insert(pg);
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

    
    int totlPF = optPR(rStr, fC); //totalPageFaults as totlPF

   
    cout << "File: " << fileName << endl;
    cout << "Reference String: ";
    for (int pg : rStr) cout << pg << " ";
    cout << "\nFrame Count: " << fC << endl;
    cout << "Total Page Faults: " << totlPF << "\n" << endl;
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
