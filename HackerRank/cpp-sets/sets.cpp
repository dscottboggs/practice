#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

// define the unless macro (if not)
#ifndef unless
#define unless(condition) if(not(condition))
#else
#error unless already defined!
#endif
using namespace std;

#ifdef DEBUG
#error DEBUG was already defined!
#else
#define DEBUG false
#endif

#ifdef DEBUG_MSG
#error DEBUG_MSG was already defined!
#else
#define DEBUG_MSG if(DEBUG) cerr
#endif

struct InvalidQuery : exception {
	int value;
	InvalidQuery(int v) { value = v; }
	const char* what() const throw() {
		ostringstream builder;
		builder << "invalid query value "
						<< value;
		return builder.str().c_str();
	}
};

const char* YES = "Yes\n";
const char* NO = "No\n";

enum QueryType {
  Add = 1,
  Delete,
  Find,
};

string queryToString(QueryType query) {
	switch(query) {
	case Add: return "add";
	case Delete: return "delete";
	case Find: return "find";
	default: throw runtime_error("should be unreachable, query is an enum");
	}
}

QueryType getQuery(int *value) {
 	int query;
	cin >> query >> (*value);
	if (query > 3 || query < 1 ) throw InvalidQuery(query);
	return (QueryType)query;
}

class Store {
	set<int> *data;
public:
	Store() {
		data = new set<int>;
	};
	~Store() { free(data); }
	void process(QueryType query, int value) {
		DEBUG_MSG << "got "
							<< queryToString(query)
							<< " request with value "
							<< value
							<< '\n';
		switch(query){
		case Add: return add(value);
		case Delete: return del(value);
		case Find: return loc(value);
		}
	}
private:
	inline void add(int value) { data->insert(value); }
	inline void del(int value) { data->erase(value); }
	inline void loc(int value) {
		if (data->count(value)) {
			cout << YES;
		} else { cout << NO; }
	}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int count;
	cin >> count;
	auto data = new Store;
	int value;
	while(count--) {
		auto query = getQuery(&value);
		data->process(query, value);
	}
  return 0;
}
