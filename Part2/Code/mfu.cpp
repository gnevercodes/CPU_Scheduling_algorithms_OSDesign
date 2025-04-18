#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

//MFU implementation
int findMFU(const vector<int>& fam, const unordered_map<int, int>& fqncy, const vector<int>& insrtOrd) {
    int mfu_pg = fam[0];
    int max_fqncy = fqncy.at(mfu_pg);

    for (int pg : fam) {
        if (fqncy.at(pg) > max_fqncy) {
            mfu_pg = pg;
            max_fqncy = fqncy.at(pg);
        } else if (fqncy.at(pg) == max_fqncy) {
            // Use FIFO order
            auto it1 = find(insrtOrd.begin(), insrtOrd.end(), mfu_pg);
            auto it2 = find(insrtOrd.begin(), insrtOrd.end(), pg);
            if (it2 < it1) {
                mfu_pg = pg;
            }
        }
    }
    return mfu_pg;
}


int mfuPgR(const vector<int>& rStr, int fC) {
    vector<int> fam; 
    unordered_map<int, int> fqncy; // To store frequency of pages
    vector<int> insrtOrd; // To track FIFO order of pages in frames
    int pgF = 0;

    for (int pg : rStr) {
    
        fqncy[pg]++;


        if (find(fam.begin(), fam.end(), pg) != fam.end()) {
            continue; 
        }


        pgF++;

        if (fam.size() < fC) {
   
            fam.push_back(pg);
            insrtOrd.push_back(pg); // Track the insertion order
        } else {
   
            int mfu_pg = findMFU(fam, fqncy, insrtOrd);

          
            auto it = find(fam.begin(), fam.end(), mfu_pg);
            if (it != fam.end()) {
 fam.erase(it);
            }

    
            auto itOrder = find(insrtOrd.begin(), insrtOrd.end(), mfu_pg);
            if (itOrder != insrtOrd.end()) {
                insrtOrd.erase(itOrder);
            }


            fam.push_back(pg);
            insrtOrd.push_back(pg); 

            // Reset the frequency of the replaced page to 0
            fqncy[mfu_pg] = 0;
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

    string line;
    vector<int> rStr;
    int fC = 0;

    while (getline(inputFile, line)) {
        if (line.find("Reference String:") != string::npos) {
            // Extract the reference string after "Reference String:"
            string refStr = line.substr(line.find(":") + 1);
            rStr.clear();
            stringstream refStream(refStr);
            string pageStr;
            while (getline(refStream, pageStr, ',')) {
                rStr.push_back(stoi(pageStr)); 
            }
        } else if (line.find("Frame Count:") != string::npos) {
            // Extract the frame count after "Frame Count:"
            string frameCountStr = line.substr(line.find(":") + 1);
            fC = stoi(frameCountStr); 

            int totlPgF = mfuPgR(rStr, fC);


            cout << "Reference String: ";
            for (int pg : rStr) cout << pg << " ";
            cout << "\nFrame Count: " << fC << endl;
            cout << "Total Page Faults: " << totlPgF << "\n" << endl;
        }
    }

    inputFile.close();
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


    pTC(argv[1]);

    return 0;
}
