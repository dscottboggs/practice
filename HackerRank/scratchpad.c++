
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void split(string line, vector<string> *result){ split(line, result, ' '); }
void split(string line, vector<string> *result, char delimiter) {
    stringstream lineStream(line);
    string substring;
    while (getline(lineStream, substring, delimiter)) {
        if (!substring.empty()) result->push_back(substring);
    }
}
vector<string>* split(string line){ return split(line, ' '); }
vector<string>* split(string line, char delimiter){
    vector<string> *result;
    split(line, result, delimiter);
    return result;
}
void split(string line, vector<int> *result, char delimiter){
    stringstream lineStream(line);
    string substring;
    while( getline(lineStream, substring, delimiter) ){
        if( !substring.empty() ) result->push_back( strtoi(substring) );
    }
}
void split(string line, vector<int> *result){ split(line, result, ' '); }
vector<int>* split(string line){ return split(line, ' '); }
vector<int>* split(string line, char delimiter){
    vector<int> *result;
    split(line, result, delimiter);
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nArrays, nQueries;
    cin >> nArrays >> nQueries;
    vector< vector<string> > allLinesArrays;
    for(unsigned int index=0; index<nArrays; index++){
        string thisLine;
        getline(cin, thisLine);
        vector<string> *thisLineArray = split(thisLine);
        allLinesArrays.push_back(thisLineArray);
    }
    for (unsigned int i = 0; i < nQueries; i++) {
        string theseCoords;
        getline(cin, theseCoords);
        vector<int> *coords = split(theseCoords);
        int x = theseCoords[0]; int y = theseCoords[1];
        cout << allLinesArrays[x][y] << '\n';
    }
    return 0;
}
