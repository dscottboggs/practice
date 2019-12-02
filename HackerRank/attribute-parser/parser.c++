#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class failed_assertion: public exception {
	string message;
public:
	failed_assertion(string msg): message{msg} {};
	const char *what() {
		return message.c_str();
	}
};
namespace HRML {
	class Attribute {
	private:
		string key; string value;
	public:
		Attribute(istream &in) {
			string equals;
			in >> key >> equals >> value;
			if(equals != "="){
				ostringstream errmsg;
				errmsg << "parsing error! expected '"
					   << key << ' ' << equals << ' ' << value
					   << "' to be " << key << " = " << value;
				throw failed_assertion(errmsg.str());
			}
	   	}
	};
	class Tag {
	private:
		string title;
		vector<Attribute> attributes;
	public:
		Tag() {
			string scratch;
		 	getline(cin, scratch);
			istringstream pull { scratch };
			pull >> title;
			title.erase(0,1);
			if(title[title.size() - 1] == '>') {
				title.erase(title.size() - 2, title.size() - 1);
				return;
			}
			while(pull) {
				Attribute attr { pull };
				attributes.push_back(attr);
			}
			auto last = attributes[attributes.size() - 1];
			last.value.erase(last.size() - 1, last.size() - 2);
		}
	};
	class Text {};
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

