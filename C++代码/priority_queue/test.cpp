#include"priority_queue.h"
#include<iostream>
using namespace std;
using namespace bin;

int main()
{
	//Ĭ���Ǵ��
	//priority_queue<int> pq;
	//С��
	priority_queue<int, vector<int>, bin::greater<int>> pq;
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}