#include <iostream>
#include <string>

using namespace std;
class error
{
	string str;
public:
	error(string s) { str = s; }
	void what() { cout << str << endl; }
};

const int MAX_SIZE = 20;

class Vector
{
private:
	int size;
	int* beg;
public:
	Vector()
	{
		size = 0;
		beg = 0;
	}
	Vector(int s)
	{
		if (s > MAX_SIZE) throw error("Длина вектора больше макс. размера\n");
		size = s;
		beg = new int[s];
		for (int i = 0; i < size; i++)
			beg[i] = 0;
	}
	Vector(int s, int* mas)
	{
		if (s > MAX_SIZE) throw error("Длина вектора больше макс. размера\n");
		size = s;
		beg = new int[s];
		for (int i = 0; i < size; i++)
			beg[i] = mas[i];
	}
	Vector(const Vector& v)
	{
		size = v.size;
		beg = new int[size];
		for (int i = 0; i < size; i++)
			beg[i] = v.beg[i];
	}
	~Vector()
	{
		if (beg != 0) delete[]beg;
	}
	Vector& operator=(const Vector& v)
	{
		if (this == &v) return *this;
		if (beg != 0) delete[]beg;
		size = v.size;
		beg = new int[size];
		for (int i = 0; i < size; i++)
			beg[i] = v.beg[i];
		return *this;
	}
	int operator[](int i)
	{
		if (i < 0) throw error("Индекс < 0\n");
		if (i >= size) throw error("Индекс > размера вектора\n");
		return beg[i];
	}
	Vector operator+(int a)
	{
		for (int i = 0; i < a; i++)
		{
			if (size + 1 >= MAX_SIZE) throw error("Превышен макс. размер\n");
			size++;
		}
		Vector tmp(size, beg);
		for (int i = size - a; i < size; i++)
		{
			tmp.beg[i] = a;
		}
		return tmp;
	}
	Vector operator-(int a)
	{
		for (int i = 0; i < a; i++)
		{
			if (size - 1 < 0) throw error("Число убранных элементов больше, чем размер самого вектора");
			size--;
		}
		Vector tmp(size, beg);
		delete[]beg;
		beg = new int[size];
		for (int i = 0; i < size; i++)
		{
			beg[i] = tmp.beg[i];
		}
		return *this;
	}
	int operator()()
	{
		return size;
	}
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
};

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Пустой\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		Vector x(4);
		Vector y(1);
		cout << x;
		cout << "Индекс: ";
		int i;
		cin >> i;
		cout << x[i] << endl;
		cout << "Размер x: " << x() << endl;
		y = y + 3;
		cout << y;
		x = x - 3;
		cout << x;
		cout << "Размер x: " << x() << endl;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}