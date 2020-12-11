#include <iostream>

using namespace std;

class Date
{
public:

	//����ÿ���ж�����
	int GetMonthday(int year, int month)
	{
		//ÿ��0�£����Դ��±�1��ʼ�洢
		int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//�ж����꣬�����2����29��
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthday[month];
	}

	//���캯��
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthday(year, day))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}
	}

	//��������
	~Date()
	{

	}

	//�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day; 
	}

	//���������
	//d1=d2,��ֵ�����
	Date& operator=(const Date& d)
		//����������*this���ڣ������ʹ�����÷��أ��봫ֵ������ȿ��Լ���һ�ο�������
	{
		//�Լ����ܸ�ֵ���Լ���d3=d3
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day; 
		}
		return *this;
	}

	//�Ƚ������

	//d1==d2
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//d1!=d2����>!(d1==d2)
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//d1<d2
	//bool operator<(Date* this,const Date& d)
	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year = d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		return false;
	}

	//d1<=d2����> d1<d2||d1==d2
	//d1.operator<=(&d1,d2)
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	//d1>d2����>!(d1<=d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	//d1>=d2����>!(d1<d2)
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	//d1+����
	Date operator+(int day)
	{
		//��������һ��d1
		Date ret = *this;
		//day�Ǹ���
		if (day < 0)
		{
			day = -day;
			return ret - day;
		}
		ret._day += day;
		//����֮����������Ϸ��ͽ���ѭ��
		while (ret._day > GetMonthday(ret._year, ret._month))
		{
			//�������Ϸ��������½�λ
			ret._day -= GetMonthday(ret._year, ret._month);
			ret._month++;
			//�����������12���£��������λ
			if (ret._month == 13)
			{
				ret._year++;
				//������1�����¿�ʼ
				ret._month = 1;
			}
		}
		return ret;
	}

	//d1+=10
	Date& operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}

	//d1-10
	Date operator-(int day)
	{
		Date ret = *this;
		//��������һ��d1
		if (day < 0)
		{
			day = -day;
			return ret + day;
		}
		ret._day -= day;
		//ret._dayС�ڵ���0���Ϸ�����ȥ�½�����
		while (ret._day <= 0)
		{
			ret._month--;
			if (ret._month == 0)
			{
				ret._month = 12;
				ret._year--;
			}
			ret._day += GetMonthday(ret._year, ret._month);
		}
		return ret;
	}

	//d1-=10
	Date& operator-=(int day)
	{
		*this = *this - day;
		return *this;
	}
	
	//����++�����ؼ�֮ǰ��ֵ
	Date operator++(int) //Ϊ�˹�������
	{
		//�Ѽ�֮ǰ��ֵ��������
		Date tmp(*this);
		*this += 1;
		//���ؼ�֮ǰ��ֵ
		return tmp;
	}
	//ǰ��++�����ؼ�֮���ֵ
	Date& operator++()
	{ 
		*this += 1;
		//���ؼ�֮���ֵ
		return *this;
	}

	//ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	//����--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return *this;
	}

	//�������d1-d2
	int operator-(const Date& d)
	{
		//���ű�־λ
		int flag = 1;
		//����������������
		Date min(*this);
		Date max(d);
		//�ж��������ڵĴ�С
		if (min > max)
		{
			min = d;
			max = *this;
			flag = -1;
		}
		//�ҳ�С���Ǹ����ڣ�Ȼ�����++��֪�������������
		int day = 0;
		while (min != max)
		{
			//�Զ������ͣ����Ե���ǰ�ã��Ͳ����ú���
			//����++��Ҫ���ÿ�������
			++min;
			day++;
		}
		//����++�Ĵ�����������������
		return flag * day;
	}

	//��ӡ
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day; 
};

int main()
{
	Date d1;
	d1 += 10;
	d1.Print();

	Date d2(2020,9,2);
	d2.Print();

	cout << (d1 == d2) << endl; 
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 != d2) << endl;

	Date d3 = d2 + 1000;
	d3.Print();

	Date d4(2020,9,11);
	d4 -= 10;
	d4.Print();

	Date d5 = d4 - 10;
	d5.Print();

	return 0;
}