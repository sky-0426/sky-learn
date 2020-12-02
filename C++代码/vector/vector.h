#pragma once
#include<cstring>
#include<cassert>
#include<iostream>
using namespace std;

namespace bin {
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			,end_of_storage(nullptr)
		{}

		//拷贝构造
		//vector(const vector<T>& v)
		//{
		//	//深拷贝
		//	//开空间
		//	_start = new T[v.size()];
		//	_finish = _start + v.size();
		//	end_of_storage = _start + v.capacity();
		//	//拷贝数据
		//	memcpy(_start, v._start, sizeof(T) * v.size());
		//}
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		//赋值运算符重载
		vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
			return *this;
		}

		//swap()
		void swap(vector<T>& v)
		{
			//调用全局函数swap
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(end_of_storage, v.end_of_storage);
		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = end_of_storage = nullptr;
		}

		//operator[]运算符重载
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		//begin()返回一个指向当前vector起始元素的迭代器
		iterator begin()
		{
			return _start;
		}
		const_iterator begin() const
		{
			return _start;
		}

		//end()返回一个指向当前vector末尾元素的下一位置的迭代器
		iterator end()
		{
			return _finish;
		}
		const_iterator end() const
		{
			return _finish;
		}

		//reserve()为当前vector预留至少共容纳n个元素的空间
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				//开辟新空间
				T* tmp = new T[n];
				if (_start)
				{
					//拷贝数据,memcpy是按字节拷贝,如果vector<string>,引出深层次的深浅拷贝问题
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; ++i)
					{
						//解决深浅拷贝问题，这里用赋值
						tmp[i] = _start[i];
					}
					//释放旧空间
					delete[] _start;
				}
				//指向新空间 
				_start = tmp;
				//重新计算_finish和end_of_storage
				_finish = tmp + sz;
				end_of_storage = _start + n;
			}
		}

		//resize()改变当前vector的大小为size,且对新创建的元素赋值val
		void resize(size_t n, const T& val = T())
		{
			//n小于当前容器的大小size()，则将内容减少到其前n个元素
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					//如果n大于当前容器容量，将重新分配存储空间
					reserve(n);
				}
				//n大于当前容器的大小,在末尾插入元素来达到n
				//如果指定了val，则将新元素初始化为val
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		//push_back()添加值为x的元素到当前vector末尾
		void push_back(const T& x)
		{
			/*if (_finish == end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;*/

			insert(end(), x);
		}

		//pop_back()删除当前vector最末的一个元素
		void pop_back()
		{
			/*assert(_start < _finish);
			--_finish;*/

			erase(end() - 1);
		}

		//insert()插入
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == end_of_storage)
			{
				//内部迭代器失效，则先计算出来pos到_start的距离
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				//增容后pos迭代器失效，在新申请的空间中重新计算pos的位置
				pos = _start + n;
			}
			//pos之后的元素往后移
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			//将x插入pos位置
			*pos = x;
			//当前vector的大小加1
			++_finish;
		}

		//erase()删除
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			//返回删除之后的下一个位置
			return pos;
		}

		//size()返回当前vector所容纳元素的数目 
		size_t size() const
		{
			return _finish - _start;
		}

		//capacity()返回当前vector在重新进行内存分配以前所能容纳的元素数量
		size_t capacity() const
		{
			return end_of_storage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator end_of_storage;
	};
}
