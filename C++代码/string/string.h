#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <string.h>

//namespace mystring
//{
//	class string
//	{
//	public:
//		//���캯����ȫȱʡ
//		string(char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//		//��������
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		//�������캯�������
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
//		//operator= ��ֵ���������
//		string& operator=(const string& s)
//		{
//			//��ֹ�Լ����Լ���ֵ
//			if (this != &s)
//			{
//				//����ͬ����С�Ŀռ�
//				char* tmp = new char[strlen(s._str) + 1];
//				//�����ݿ�����ȥ
//				strcpy(tmp, s._str);
//				//�ͷ�ԭ���Ŀռ�
//				delete[] _str;
//				//���µ����ݸ�ֵ��ȥ
//				_str = tmp;
//			}
//			return *this;
//		}
//		//operator[] ���������
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
//		//ָ��
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
		//���캯��
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//��������
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
		//operator= ��ֵ���������
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
			//�ռ����˽�������
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
