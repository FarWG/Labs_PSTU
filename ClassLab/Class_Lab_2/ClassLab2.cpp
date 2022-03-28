#include <iostream>
#include <string>

using namespace std;

class book
{
private:
	string name;
	string author;
	int year;
public:
	void set(string name, string author, int year)
	{
		this->name = name;
		this->author = author;
		this->year = year;
	}
	void def()
	{
		name = "Дюна";
		author = "Френк Герберт";
		year = 1965;
	}
	void copy(const book& a)
	{
		name = a.name;
		author = a.author;
		year = a.year;
	}
	void print()
	{
		cout << "Название: " << name
			<< "\nАвтор: " << author
			<< "\nГод издания: " << year << endl;
	}
	~book()
	{
		cout << "Сработал Деструктор" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	book a, b, c;
	cout << "Конструктор с параметрами" << endl;
	a.set("Пикник на обочине", "Братья Стругацкие", 1972);
	a.print();
	cout << endl;
	cout << "Конструктор без параметров" << endl;
	b.def();
	b.print();
	cout << endl;
	cout << "Конструктор копирования" << endl;
	c.copy(a);
	c.print();
	cout << endl;
	return 0;
}