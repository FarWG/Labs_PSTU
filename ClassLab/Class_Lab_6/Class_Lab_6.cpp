#include <iostream>

using namespace std;

class Iterator
{
private:
	friend class vector;
	int* elem;
public:
	Iterator()
	{
		elem = 0;
	}
	Iterator(const Iterator& tmp)
	{
		elem = tmp.elem;
	}
	bool operator==(const Iterator& tmp)
	{
		return elem == tmp.elem;
	}
	bool operator!=(const Iterator& tmp)
	{
		return elem != tmp.elem;
	}
	void operator++()
	{
		++elem;
	}
	void operator--()
	{
		--elem;
	}
	int& operator*()
	{
		return *elem;
	}
};

class vector
{
private:
	int size;
	int* cur;
	Iterator beg;
	Iterator end;
public:
	vector(int s, int k = 0)
	{
		size = s;
		cur = new int[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = k;
		}
		beg.elem = &cur[0];
		end.elem = &cur[size];
	}
	vector(const vector& tmp)
	{
		size = tmp.size;
		cur = new int[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = tmp.cur[i];
		}
		beg = tmp.beg;
		end = tmp.end;
	}
	vector& operator=(const vector& tmp)
	{
		if (this == &tmp)
		{
			return *this;
		}
		size = tmp.size;
		if (cur != 0)
		{
			delete[]cur;
		}
		cur = new int[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = tmp.cur[i];
		}
		beg = tmp.beg;
		end = tmp.end;
		return *this;
	}
	vector& operator+(const int t)
	{
		vector tmp(size);
		for (int i = 0; i < size; i++)
		{
			tmp.cur[i] += cur[i] + t;
		}
		return tmp;
	}
	int& operator[](int i)
	{
		if (i < size)
		{
			return cur[i];
		}
		else
		{
			cout << "i > размер вектора" << endl;
		}
	}
	int operator()()
	{
		return size;
	}
	friend ostream& operator<<(ostream& out, const vector& tmp);
	friend istream& operator>>(istream& in, vector& tmp);
	Iterator first()
	{
		return beg;
	}
	Iterator last()
	{
		return end;
	}
};

ostream& operator<<(ostream& out, const vector& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << tmp.cur[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, vector& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		in >> tmp.cur[i];
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector a(5);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n";
	vector b(10);
	cout << b << "\n";
	b = a;
	cout << b << "\n";
	vector c(10);
	c = b + 100;
	cout << c << "\n";
	cout << "Длина а = " << a() << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << *i << endl;
	for (i = a.first(); i != a.last(); ++i)
	{
		cout << *i << endl;
	}
}