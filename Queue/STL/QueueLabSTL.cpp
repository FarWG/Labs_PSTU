#include <iostream>
#include <queue>

using namespace std;

void print(queue<char> q)
{
	int num = q.size();
	for (int i = 0; i < num; i++)
	{
		cout << q.front();
		q.pop();
	}
}

void change(queue<char>& q, int& n)
{
	int count = 1;
	while (count <= n)
	{
		if (count % 2 != 0)
		{
			char a;
			cin >> a;
			q.push(a);
			q.pop();
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		count++;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	char a;
	cout << "Введите размер очереди: ";
	cin >> n;
	queue<char> qu;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		qu.push(a);
	}
	print(qu);
	cout << endl;
	change(qu, n);
	cout << endl;
	print(qu);
	return 0;
}