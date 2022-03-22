#include <iostream>
#include <string>

using namespace std;

int Search(string str, string sbstr)
{
	int st, sbst;
	st = str.size();
	sbst = sbstr.size();
	int* d = new int[sbst];
	int i = 0;
	int j = -1;
	d[0] = -1;
	while (i < sbst - 1)
	{
		while ((j >= 0) && (sbstr[j] != sbstr[i]))
		{
			j = d[j];
		}
		i++;
		j++;
		if (sbstr[i] == sbstr[j])
		{
			d[i] = d[j];
		}
		else
		{
			d[i] = j;
		}
		i = 0;
		j = 0;
		for (i = 0, j = 0; (i <= st - 1) && (j <= sbst - 1); i++, j++)
		{
			while ((j >= 0) && (sbstr[j] != str[i]))
			{
				j = d[j];
			}
		}
		delete[] d;
		if (j == sbst)
		{
			return i - j;
		}
		else return -1;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string st;
	cout << "Введите строку: ";
	cin >> st;
	string sbst;
	string* st2 = new string[st.size()];
	cout << "Введите подстроку: ";
	cin >> sbst;
	int ist = Search(st, sbst);
	if (ist == -1)
	{
		cout << "Не найден";
		return 0;
	}
	int size = sbst.size();
	for (int i = 0; i < size; i++)
	{
		*st2 += sbst[i];
	}
	for (int i = 0; i < ist; i++)
	{
		*st2 += st[i];
	}
	int i = ist;
	while (st[i + size] != '\0')
	{
		*st2 += st[i + size];
		i++;
	}
	cout << "Итоговая строка: ";
	cout << *st2;
	delete[]st2;
	return 0;
}