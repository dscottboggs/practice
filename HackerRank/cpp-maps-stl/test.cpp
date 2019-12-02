 #include <iostream>
#include <map>

int main()
{
	std::map<char,int> data;

 data['a'] = 50;
 data['b'] = 100;

 auto it = data.find('b');
 data.erase(it);
 it = data.find('b');
 std::cout << it->second;

 return 0;
}
