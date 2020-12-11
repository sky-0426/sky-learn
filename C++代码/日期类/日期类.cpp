#include <iostream>

using namespace std;

class Date
{
public:

	//计算每月有多少天
	int GetMonthday(int year, int month)
	{
		//每月0月，所以从下标1开始存储
		int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//判断闰年，闰年的2月有29天
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthday[month];
	}

	//构造函数
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
			cout << "非法日期" << endl;
		}
	}

	//析构函数
	~Date()
	{

	}

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day; 
	}

	//运算符重载
	//d1=d2,赋值运算符
	Date& operator=(const Date& d)
		//出了作用域*this还在，则可以使用引用返回，与传值返回相比可以减少一次拷贝构造
	{
		//自己不能赋值给自己，d3=d3
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day; 
		}
		return *this;
	}

	//比较运算符

	//d1==d2
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//d1!=d2——>!(d1==d2)
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

	//d1<=d2——> d1<d2||d1==d2
	//d1.operator<=(&d1,d2)
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	//d1>d2——>!(d1<=d2)
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	//d1>=d2——>!(d1<d2)
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	//d1+天数
	Date operator+(int day)
	{
		//拷贝构造一个d1
		Date ret = *this;
		//day是负数
		if (day < 0)
		{
			day = -day;
			return ret - day;
		}
		ret._day += day;
		//加完之后的天数不合法就进入循环
		while (ret._day > GetMonthday(ret._year, ret._month))
		{
			//天数不合法，就往月进位
			ret._day -= GetMonthday(ret._year, ret._month);
			ret._month++;
			//如果月数够了12个月，就往年进位
			if (ret._month == 13)
			{
				ret._year++;
				//月数从1月重新开始
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
		//拷贝构造一个d1
		if (day < 0)
		{
			day = -day;
			return ret + day;
		}
		ret._day -= day;
		//ret._day小于等于0不合法，则去月借天数
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
	
	//后置++，返回加之前的值
	Date operator++(int) //为了构成重载
	{
		//把加之前的值保存起来
		Date tmp(*this);
		*this += 1;
		//返回加之前的值
		return tmp;
	}
	//前置++，返回加之后的值
	Date& operator++()
	{ 
		*this += 1;
		//返回加之后的值
		return *this;
	}

	//前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	//后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return *this;
	}

	//日期相减d1-d2
	int operator-(const Date& d)
	{
		//符号标志位
		int flag = 1;
		//拷贝构造两个对象
		Date min(*this);
		Date max(d);
		//判断两个日期的大小
		if (min > max)
		{
			min = d;
			max = *this;
			flag = -1;
		}
		//找出小的那个日期，然后进行++，知道两个日期相等
		int day = 0;
		while (min != max)
		{
			//自定义类型，可以调用前置，就不调用后置
			//后置++需要调用拷贝构造
			++min;
			day++;
		}
		//返回++的次数，就是相差多少天
		return flag * day;
	}

	//打印
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