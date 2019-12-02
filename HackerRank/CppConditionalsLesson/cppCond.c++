#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getWordFor(int n){
    switch(n){
        case 1: return "one"; break;
        case 2: return "two"; break;
        case 3: return "three"; break;
        case 4: return "four"; break;
        case 5: return "five"; break;
        case 6: return "six"; break;
        case 7: return "seven"; break;
        case 8: return "eight"; break;
        case 9: return "nine"; break;
        default: return "Greater than 9";
    }
}

int main(int argc, char* argv[]) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    if(argc==1){
		cin >> n;
	}
	else if(argc==2){
		n=atoi(argv[2]);
	}
	else{
		cout << "error";
		return 1;
	}
	cout << getWordFor(n) << "\n";
    return 0;
}
