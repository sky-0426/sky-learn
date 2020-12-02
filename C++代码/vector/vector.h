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

		//���캯��
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			,end_of_storage(nullptr)
		{}

		//��������
		//vector(const vector<T>& v)
		//{
		//	//���
		//	//���ռ�
		//	_start = new T[v.size()];
		//	_finish = _start + v.size();
		//	end_of_storage = _start + v.capacity();
		//	//��������
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

		//��ֵ���������
		vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
			return *this;
		}

		//swap()
		void swap(vector<T>& v)
		{
			//����ȫ�ֺ���swap
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(end_of_storage, v.end_of_storage);
		}

		//��������
		~vector()
		{
			delete[] _start;
			_start = _finish = end_of_storage = nullptr;
		}

		//operator[]���������
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		//begin()����һ��ָ��ǰvector��ʼԪ�صĵ�����
		iterator begin()
		{
			return _start;
		}
		const_iterator begin() const
		{
			return _start;
		}

		//end()����һ��ָ��ǰvectorĩβԪ�ص���һλ�õĵ�����
		iterator end()
		{
			return _finish;
		}
		const_iterator end() const
		{
			return _finish;
		}

		//reserve()Ϊ��ǰvectorԤ�����ٹ�����n��Ԫ�صĿռ�
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				//�����¿ռ�
				T* tmp = new T[n];
				if (_start)
				{
					//��������,memcpy�ǰ��ֽڿ���,���vector<string>,�������ε���ǳ��������
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; ++i)
					{
						//�����ǳ�������⣬�����ø�ֵ
						tmp[i] = _start[i];
					}
					//�ͷžɿռ�
					delete[] _start;
				}
				//ָ���¿ռ� 
				_start = tmp;
				//���¼���_finish��end_of_storage
				_finish = tmp + sz;
				end_of_storage = _start + n;
			}
		}

		//resize()�ı䵱ǰvector�Ĵ�СΪsize,�Ҷ��´�����Ԫ�ظ�ֵval
		void resize(size_t n, const T& val = T())
		{
			//nС�ڵ�ǰ�����Ĵ�Сsize()�������ݼ��ٵ���ǰn��Ԫ��
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					//���n���ڵ�ǰ���������������·���洢�ռ�
					reserve(n);
				}
				//n���ڵ�ǰ�����Ĵ�С,��ĩβ����Ԫ�����ﵽn
				//���ָ����val������Ԫ�س�ʼ��Ϊval
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		//push_back()���ֵΪx��Ԫ�ص���ǰvectorĩβ
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

		//pop_back()ɾ����ǰvector��ĩ��һ��Ԫ��
		void pop_back()
		{
			/*assert(_start < _finish);
			--_finish;*/

			erase(end() - 1);
		}

		//insert()����
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == end_of_storage)
			{
				//�ڲ�������ʧЧ�����ȼ������pos��_start�ľ���
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				//���ݺ�pos������ʧЧ����������Ŀռ������¼���pos��λ��
				pos = _start + n;
			}
			//pos֮���Ԫ��������
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			//��x����posλ��
			*pos = x;
			//��ǰvector�Ĵ�С��1
			++_finish;
		}

		//erase()ɾ��
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
			//����ɾ��֮�����һ��λ��
			return pos;
		}

		//size()���ص�ǰvector������Ԫ�ص���Ŀ 
		size_t size() const
		{
			return _finish - _start;
		}

		//capacity()���ص�ǰvector�����½����ڴ������ǰ�������ɵ�Ԫ������
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
