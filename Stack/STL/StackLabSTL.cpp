#include <iostream>
#include <stack>

using namespace std;

void print(stack<double> st)
{
	int num = st.size();
	for (int i = 0; i < num; i++)
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	double k;
	cout << "Введите размера стека: ";
	cin >> n;
	stack<double> st;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		st.push(k);
	}
	print(st);
	cout << endl;
	stack<double> st2;
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		if (count % 2 == 0)
		{
			st2.push(st.top());
		}
		st.pop();
		count++;
	}
	int num2 = st2.size();
	for (int i = 0; i < num2; i++)
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	return 0;
}