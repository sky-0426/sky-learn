#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <string.h>

//namespace mystring
//{
//	class string
//	{
//	public:
//		//构造函数，全缺省
//		string(char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//		//析构函数
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		//拷贝构造函数，深拷贝
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		//size()
//		size_t size()
//		{
//			return strlen(_str);
//		}
//		//operator= 赋值运算符重载
//		string& operator=(const string& s)
//		{
//			//防止自己给自己赋值
//			if (this != &s)
//			{
//				//开辟同样大小的空间
//				char* tmp = new char[strlen(s._str) + 1];
//				//将内容拷贝过去
//				strcpy(tmp, s._str);
//				//释放原来的空间
//				delete[] _str;
//				//将新的内容赋值过去
//				_str = tmp;
//			}
//			return *this;
//		}
//		//operator[] 运算符重载
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//		//c_str()
//		const char* c_str()
//		{
//			return _str;
//		}
//	private:
//		//指针
//		char* _str;
//	};
//}
namespace mystring
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//构造函数
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//拷贝构造
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}
		//s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//operator= 赋值运算符重载
		string& operator=(string s)
		{
			this->swap(s);
			return *this;
		}
		//size()
		size_t size() const
		{
			return _size; 
		}
		//capacity()
		size_t capacity() const
		{
			return _capacity;
		}
		//operator[]
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}
		//c_str
		const char* c_str()
		{
			return _str;
		}
		//reserve()
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
			
		}
		//push_back()
		void push_back(char ch)
		{
			//空间满了进行扩容
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		//append()
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		//operator+=
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	/*istream& operator>>(istream& in, string& s)
	{

	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << s[i];
		}
		return out;
	}*/
}
