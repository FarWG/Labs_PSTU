#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
	int size;
	T* data;
public:
	Vector(int s, T tmp)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp;
		}
	}
	/*Vector(int s, Vector<T> tmp)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp.data[i];
		}
	}*/
	Vector(const Vector<T>& tmp)
	{
		size = tmp.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp.data[i];
		}
	}
	~Vector()
	{
		delete[]data;
		data = 0;
	}
	Vector& operator=(const Vector<T>& tmp)
	{
		if (this == &tmp)
		{
			return *this;
		}
		size = tmp.size;
		if (data != 0)
		{
			delete[]data;
		}
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp.data[i];
		}
		return *this;
	}
	T& operator[](int index)
	{
		if (index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Индекс больше размера вектора" << endl;
			return data[0];
		}
	}
	Vector operator+(const Vector<T> tmp)
	{
		T a(0, 0);
		Vector<T> tmp2(size, a);
		if (size >= tmp.size)
		{
			for (int i = 0; i < tmp.size; i++)
			{
				tmp2.data[i] = data[i] + tmp.data[i];
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				tmp2.data[i] = data[i] + tmp.data[i];
			}
		}
		return tmp2;
	}
	int operator()()
	{
		return size;
	}
	friend ostream& operator<< <>(ostream& out, const Vector<T>& tmp);
	friend istream& operator>> <>(istream& in, Vector<T>& tmp);
};
template <class T>
ostream& operator<< <>(ostream& out, const Vector<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << tmp.data[i] << " ";
	}
	return out;
}

template <class T>
istream& operator>> <>(istream& in, Vector<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		in >> tmp.data[i];
	}
	return in;
}

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
	Time& operator=(const Time& t)
	{
		if (&t == this) {
			return *this;
		}
		min = t.min;
		sec = t.sec;
		return *this;
	}
	Time operator+(Time tmp)
	{
		int tm = min * 60 + tmp.min * 60 + sec + tmp.sec;
		Time tmp2(tm / 60, tm % 60);
		return tmp2;
	}
	friend ostream& operator<<(ostream& out, const Time& tmp);
	friend istream& operator>>(istream& in, Time& tmp);
	~Time()
	{
	}
};

ostream& operator<<(ostream& out, const Time& tmp)
{
	return (out << "(" << tmp.min << " : " << tmp.sec << ")");
}
istream& operator>>(istream& in, Time& tmp)
{
	cout << "\nmin?";
	in >> tmp.min;
	cout << "\nsec?";
	in >> tmp.sec;
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	/*Vector<int>A(5, 0);
	cin >> A;
	cout << A << endl;
	Vector<int>B(10, 1);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "Размер А = " << A() << endl;
	A = A + B;
	cout << A << endl;*/
	Time t(10, 45);
	cout << t;
	Vector<Time>Q(5, t);
	cin >> Q;
	cout << Q << endl;
	Vector<Time>W(10, t);
	cout << W << endl;
	W = Q;
	cout << W << endl;
	cout << Q[2] << endl;
	cout << "Размер Q = " << Q() << endl;
	Q = Q + W;
	cout << Q << endl;
	return 0;
}