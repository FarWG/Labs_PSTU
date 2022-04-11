#include <iostream>

using namespace std;

class Pair
{
protected:
	int first;
	int second;
public:
	Pair()
	{
		first = 0;
		second = 0;
	}
	Pair(int f, int s)
	{
		first = f;
		second = s;
	}
	Pair(const Pair& tmp)
	{
		first = tmp.first;
		second = tmp.second;
	}
	void setFirst(int f)
	{
		first = f;
	}
	void setSecond(int s)
	{
		second = s;
	}
	int getFirst() { return first; }
	int getSecond() { return second; }
	Pair& operator=(const Pair& p)
	{
		if (&p == this) return *this;
		first = p.first;
		second = p.second;
		return *this;
	}
	Pair operator*(const Pair tmp)
	{
		first = first * tmp.first;
		second = second * tmp.second;
		return *this;
	}
	friend istream& operator>>(istream& in, Pair& tmp);
	friend ostream& operator<<(ostream & out, const Pair& tmp);
	virtual ~Pair()
	{
		// cout << "Удалили Pair..." << endl << endl;
	}
};

istream& operator>>(istream& in, Pair& tmp)
{
	cout << "Введите первое число: "; in >> tmp.first;
	cout << "Введите второе число: "; in >> tmp.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& tmp)
{
	return (out << "(" << tmp.first << "," << tmp.second << ")");
}

class Rect : public Pair
{
public:
	int P()
	{
		int p;
		p = (first + second) * 2;
		return p;
	}
	int S()
	{
		int s;
		s = first * second;
		return s;
	}
	Rect()
	{
		first = 0;
		second = 0;
	}
	Rect(int f, int s)
	{
		first = f;
		second = s;
	}
	Rect(const Rect& tmp)
	{
		first = tmp.first;
		second = tmp.second;
	}
	void setFirst(int f)
	{
		first = f;
	}
	void setSecond(int s)
	{
		second = s;
	}
	int getFirst() { return first; }
	int getSecond() { return second; }
	Rect& operator=(const Rect& p)
	{
		if (&p == this) return *this;
		first = p.first;
		second = p.second;
		return *this;
	}
	friend istream& operator>>(istream& in, Rect& tmp);
	friend ostream& operator<<(ostream& out, const Rect& tmp);
	~Rect()
	{
		// cout << "Удалили Rect..." << endl << endl;
	}
};

istream& operator>>(istream& in, Rect& tmp)
{
	cout << "Введите одну сторону прямоугольника: "; in >> tmp.first;
	cout << "Введите другую сторону прямоугольника: "; in >> tmp.second;
	return in;
}

ostream& operator<<(ostream& out, const Rect& tmp)
{
	return (out << "Одна сторона равна: " << tmp.first << " / " << "Другая стороная равна: " << tmp.second);
}

void f1(Pair& c)
{
	c.setFirst(20);
	c.setSecond(22);
	cout << c;
}

Pair f2()
{
	Rect r(50, 20);
	return r;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Pair a;
	cin >> a;
	cout << a << endl;
	Pair b(34, 76);
	cout << b << endl;
	cout << "Произведение a и b = " << a * b << endl;
	a = b;
	cout << a << endl;

	Rect c;
	cin >> c;
	cout << c << endl;
	cout << "Периметр прямоугольника равен: " << c.P() << endl;
	cout << "Площадь прямоугольника равна: " << c.S() << endl << endl;

	f1(c);
	a = f2();
	cout << a;
}