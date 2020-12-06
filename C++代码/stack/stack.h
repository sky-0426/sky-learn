#pragma once
#include<deque>

namespace bin
{
	template<class T,class Container=deque<T>>
	class stack
	{
	public:

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
}
 