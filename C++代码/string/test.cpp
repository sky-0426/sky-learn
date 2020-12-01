#include "string.h"
#include <iostream>

using namespace std;

int main()
{
	mystring::string s1("hello");
	s1.append("world");

	s1 += '!';

	cout << s1.c_str() << endl;

	return 0;
}
