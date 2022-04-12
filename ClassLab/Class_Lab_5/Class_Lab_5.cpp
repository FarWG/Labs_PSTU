#include <iostream>

using namespace std;

class abstract
{
public:
	virtual void show() = 0;
};

class Pair : public abstract
{
protected:
	int first;
	int second;
public:
	void show() override
	{
		cout << first << " , " << second << endl;
	}
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
	friend ostream& operator<<(ostream& out, const Pair& tmp);
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
	void show() override
	{
		cout << first << " , " << second << endl;
	}
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

class Vector
{
private:
	abstract** beg;
	int size;
	int cur;
public:
	Vector()
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	Vector(int n)
	{
		beg = new abstract * [n];
		cur = 0;
		size = n;
	}
	void add(abstract* tmp)
	{
		if (cur < size)
		{
			beg[cur] = tmp;
			cur++;
		}
	}
	~Vector()
	{
		if (beg != 0)
		{
			delete[] beg;
		}
		beg = 0;
	}
	friend ostream& operator<<(ostream& out, const Vector& v);
};
ostream& operator<<(ostream& out, const Vector& v)
{
	cout << "Вектор:" << endl;
	if (v.size == 0)
	{
		out << "Empty" << endl;
	}
	abstract** tmp = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*tmp)->show();
		tmp++;
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Vector v(5);
	Pair a;
	cin >> a;
	Rect b;
	cin >> b;
	abstract* tmp = &a;
	v.add(tmp);
	tmp = &b;
	v.add(tmp);
	cout << v;
	return 0;
}