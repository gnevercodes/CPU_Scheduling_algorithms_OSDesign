#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


struct Page {
    int pgNum; //pageNumber as pgNum, referenceBit as refB, capacity as cap
    bool refB;

    Page(int pgNum) : pgNum(pgNum), refB(false) {}
};

// Implementation of  LRU Approximation with Second Chance Page Replacement Algorithm
int lruAproxSC(const vector<int>& pgs, int cap) {
    vector<Page> fams;   // frames as fams, pageFaults as pgF, pointer as pntr
    int pgF = 0; 
    int pntr = 0; 

    for (int curntPg : pgs) {
        bool pgFnd = false; //pageFound as pgFnd

        
        for (auto &page : fams) {
            if (page.pgNum == curntPg) {
                page.refB = true; // if the Page is hit then Set the reference bit to 1
                pgFnd = true;
                break;
            }
        }

        if (!pgFnd) {
            
            pgF++;

            if (fams.size() < cap) {
                
                fams.push_back(Page(curntPg));
            } else {
               
                while (true) {
                    if (!fams[pntr].refB) {
                        // Incase reference bit is set to 0 then replace this page
                        fams[pntr] = Page(curntPg); 
                        break;
                    } else {
                        // If reference bit is set to 1 the reset it to 0 and move the pointer
                        fams[pntr].refB = false;
                        pntr = (pntr + 1) % cap; 
                    }
                }
            }

            pntr = (pntr + 1) % cap;
        }
    }

    return pgF;
}

void pTC(const string& fileName) {
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
            // Extract the reference string
            stringstream ss(line.substr(line.find(":") + 1));
            int page;
            while (ss >> page) {
                rStr.push_back(page);
                if (ss.peek() == ',') ss.ignore(); // Ignore commas
            }
        } else if (line.find("Frame Count:") != string::npos) {
            // Extract the frame count
            fC = stoi(line.substr(line.find(":") + 1));
        }
    }
    file.close();

   
    int totalPageFaults = lruAproxSC(rStr, fC);

  
    cout << "File: " << fileName << endl;
    cout << "Reference String: ";
    for (int page : rStr) cout << page << " ";
    cout << "\nFrame Count: " << fC << endl;
    cout << "Total Page Faults of LRU(Second Chance): " << totalPageFaults << "\n" << endl;
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
