#pragma once
#include<deque>

namespace bin
{
	template<class T, class Container=deque<T>>
	class queue
	{
	public:

		//
		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_front();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& front()
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
}
