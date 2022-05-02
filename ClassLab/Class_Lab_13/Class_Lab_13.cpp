#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

int set;

class equals
{
public:
	bool operator() (int tmp)
	{
		return tmp == set;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	list<int> c1, c2;
	list <int>::iterator c1_Iter, c2_Iter;
	int tmp;
	int s;
	cout << "Введите размер списка: ";
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		cin >> tmp;
		c1.push_back(tmp);
	}
	cout << "\nИзначальный список: ";
	for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)
		cout << " " << *c1_Iter;
	cout << endl;
	auto min = min_element(c1.begin(), c1.end());
	set = *min;

	c1.remove_if(equals());
	c1.push_back(set);
	cout << "\nМинимальный элемент в конце списка: ";
	for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)
		cout << " " << *c1_Iter;
	cout << endl;
	cout << "\nКакой элемент удалить?: ";
	cin >> tmp;
	c1.remove(tmp);
	cout << "После удаления элемента: ";
	for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)
	{
		cout << " " << *c1_Iter;
	}
	cout << endl;
	auto max = max_element(c1.begin(), c1.end());
	int set2 = *max;
	int sum = set2 + set;
	for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)
	{
		tmp = *c1_Iter;
		c2.push_back(tmp + sum);
	}
	cout << "\nПосле добавления суммы макс. и мин. элементов к каждому: ";
	for (c2_Iter = c2.begin(); c2_Iter != c2.end(); c2_Iter++)
		cout << " " << *c2_Iter;
	cout << endl;
	return 0;
}