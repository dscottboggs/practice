#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getInput(int argc, char* argv[]){
	int input = 0;
	if(argc == 1){
		std::cin >> input;
	}
	else{
		input = atoi(argv[1]);
	}
	return input;
}
string getStaircase(int input){
	string staircase = "";
	for(int row = 0; row < input; row++){
		int col = 0;
		while(col < (input - row - 1)){
			staircase+=" ";
			col++;
		}
		while(col >=(input - row - 1) && col<input){
			staircase+="#";
			col++;
		}
		staircase+="\n";
	}
	return staircase;	
}
int main(int argc, char* argv[]){
	int input = getInput(argc,argv);
	cout << getStaircase(input);
	return 0;
}
