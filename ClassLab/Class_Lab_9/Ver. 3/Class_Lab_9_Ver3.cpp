#include <iostream>
#include <string>

using namespace std;

class Error
{
public:
	virtual void what() {};
};

class IndexError : public Error
{
protected:
	string msg;
public:
	IndexError() { msg = "Ошибка индексации\n"; }
	virtual void what() { cout << msg; }
};

class SizeError : public Error
{
protected:
	string msg;
public:
	SizeError() { msg = "Ошибка размера вектора\n"; }
	virtual void what() { cout << msg; }
};

class MaxSizeError : public SizeError
{
protected:
	string msg_M;
public:
	MaxSizeError() { 
		SizeError(); 
		msg_M = "Размер > MaxSize\n"; }
	virtual void what() { cout << msg << msg_M; }
};

class EmptySizeError : public SizeError
{
protected:
	string msg_E;
public:
	EmptySizeError() { 
		SizeError(); 
		msg_E = "Вектор пуст\n"; }
	virtual void what() { cout << msg << msg_E; }
};

class IndexError0 : public IndexError
{
protected:
	string msg_0;
public:
	IndexError0() { 
		IndexError(); 
		msg_0 = "Индекс < 0\n"; }
	virtual void what() { cout << msg << msg_0; }
};

class IndexErrorS : public IndexError
{
protected:
	string msg_S;
public:
	IndexErrorS() { 
		IndexError(); 
		msg_S = "Индекс > Размер вектора\n"; }
	virtual void what() { cout << msg << msg_S; }
};

class IndexError_S : public IndexError
{
protected:
	string msg_S;
public:
	IndexError_S() { 
		IndexError(); 
		msg_S = "Индекс < Размер вектора\n"; }
	virtual void what() { cout << msg << msg_S; }
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
		if (s > MAX_SIZE) throw MaxSizeError();
		size = s;
		beg = new int[s];
		for (int i = 0; i < size; i++)
			beg[i] = 0;
	}
	Vector(int s, int* mas)
	{
		if (s > MAX_SIZE) throw MaxSizeError();
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
		if (i < 0) throw IndexError0();
		if (i >= size) throw IndexErrorS();
		return beg[i];
	}
	Vector operator+(int a)
	{
		for (int i = 0; i < a; i++)
		{
			if (size + 1 >= MAX_SIZE) throw MaxSizeError();
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
			if (size - 1 < 0) throw IndexError_S();
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
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}