#include <iostream>

using namespace std;

class Time
{
private:
	int min;
	int sec;
public:
	Time()
	{
		min = 0;
		sec = 0;
	}
	Time(int m, int s)
	{
		min = m;
		sec = s;
	}
	Time(const Time& t)
	{
		min = t.min;
		sec = t.sec;
	}
	int getMin()
	{
		return min;
	}
	int getSec()
	{
		return sec;
	}
	void setMin(int m)
	{
		min = m;
	}
	void setSec(int s)
	{
		sec = s;
	}
	Time& operator=(const Time&t)
	{
		if (&t == this) {
			return *this;
		}
		min = t.min;
		sec = t.sec;
		return *this;
	}
	Time operator-(const Time& tmp);
	friend ostream& operator<<(ostream& out, const Time& tmp);
	friend void compar(const Time& tmp1, const Time& tmp2);
	~Time()
	{
		cout << "Сработал деструктор..." << endl;
	}
};

Time Time::operator-(const Time& tmp)
{
	int tm1 = min * 60 + sec;
	int tm2 = tmp.min * 60 + tmp.sec;
	Time p;
	p.min = abs(tm1 - tm2) / 60;
	p.sec = abs(tm1 - tm2) % 60;
	return p;
}

ostream& operator<<(ostream& out, const Time& tmp)
{
	return (out << tmp.min << " : " << tmp.sec);
}

void compar(const Time& tmp1, const Time& tmp2)
{
	int tm1 = tmp1.min * 60 + tmp1.sec;
	int tm2 = tmp2.min * 60 + tmp2.sec;
	if (tm1 == tm2)
	{
		cout << "Промежутки одинаковы" << endl;
	}
	else
	{
		cout << "Промежутки не одинаковы" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Time a(45, 13);
	Time b(5, 23);
	cout << "Первый промежуток - " << a << endl;
	cout << "Второй промежуток - " << b << endl;
	cout << "Разница между промежутками - " << a - b << endl << endl;
	cout << "/////" << endl << "Сравнение промежуктов:" << endl;
	compar(a, b);
	cout << "/////" << endl;
	return 0;
}