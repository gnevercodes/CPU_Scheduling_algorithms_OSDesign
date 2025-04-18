#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

// Implementation of the function to find least frequency
int findLFU(const vector<int>& fam, const unordered_map<int, int>& fqncy) {
    int lfu_pg = fam[0]; //lfu_page as lfupg
    int min_fqncy = fqncy.at(lfu_pg);

    for (int pg : fam) {
        if (fqncy.at(pg) < min_fqncy) {
            lfu_pg = pg;
            min_fqncy = fqncy.at(pg);
        }
    }
    return lfu_pg;
}

// LFU Page Replacement Algorithm
int lfuPageReplacement(const vector<int>& rStr, int fC) {
    vector<int> fam; // To store current frames
    unordered_map<int, int> fqncy; // To store frequency of pages
    int pgF = 0;

    for (int pg : rStr) {
        fqncy[pg]++; 

        
        if (find(fam.begin(), fam.end(), pg) != fam.end()) {
            continue; // No page fault
        }

        pgF++; 
        if (fam.size() < fC) {
            
            fam.push_back(pg);
        } else {
           
            int lfu_pg = findLFU(fam, fqncy);
            auto it = find(fam.begin(), fam.end(), lfu_pg);
            if (it != fam.end()) {
                fam.erase(it); // Remove LFU page
            }
            fam.push_back(pg); // Add new page
        }
    }

    return pgF;
}

void pTC(const string& fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    string line, referenceStringLine, frameCountLine;
    vector<int> rStr;
    int fC = 0;

    while (getline(inputFile, line)) {
        if (line.find("Reference String:") != string::npos) {
            // Extract the reference string after "Reference String:"
            string refStr = line.substr(line.find(":") + 1);
            stringstream refStream(refStr);
            string pageStr;
            while (getline(refStream, pageStr, ',')) {
                rStr.push_back(stoi(pageStr)); // Parse pages
            }
        } else if (line.find("Frame Count:") != string::npos) {
            // Extract the frame count after "Frame Count:"
            string frameCountStr = line.substr(line.find(":") + 1);
            fC = stoi(frameCountStr); // Parse frame count
        }
    }

    inputFile.close();

    
    if (rStr.empty() || fC == 0) {
        cerr << "Invalid input format in file: " << fileName << endl;
        return;
    }

    
    int totlPgF = lfuPageReplacement(rStr, fC);

 
    cout << "File: " << fileName << endl;
    cout << "Reference String: ";
    for (int page : rStr) cout << page << " ";
    cout << "\nFrame Count: " << fC << endl;
    cout << "Total Page Faults: " << totlPgF << "\n" << endl;
}

int main(int argc, char* argv[]) {
    
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
