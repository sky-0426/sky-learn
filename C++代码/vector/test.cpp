#include"vector.h"
#include<string>

using namespace std;

int main()
{
	bin::vector<string> v1;
	v1.push_back("11111111111111111111");
	v1.push_back("22222222222222222222");
	v1.push_back("33333333333333333333");
	v1.push_back("44444444444444444444");
	for (auto e : v1)
	{
		cout << e << endl;
	}
	return 0;
}
