#pragma once
#include<vector>
#include<iostream>
using namespace std;

namespace bin
{
	//仿函数 函数对象
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	//优先队列，默认是大堆
	template<class T,class Container=vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		//push相当于堆算法的向上调整
		void push(const T& data)
		{
			_con.push_back(data);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDown(int root)
		{
			Compare com;
			int parent = root;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//选出左右孩子中大的那一个
				//if (child + 1 < _com.size() && _con[child + 1] < _con[child])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				//if (_con[child] < _con[parent])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		Container _con;
	};
}
