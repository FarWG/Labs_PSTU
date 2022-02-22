#include <iostream>

using namespace std;

void quicksort(int *a, int first, int last)
{
	int tmp = 0;
	int f = first;
	int l = last;  
	int d = a[(f + l) / 2];
	while (f < l)
	{
		while (a[f] < d)
		{
			cout << a[f] << " " << d << endl;
			f++;
		}
		while (a[l] > d)
		{
			cout << a[l ] << " " << d << endl;
			l--;
		}
		if (f <= l)
		{
			tmp = a[f];
			a[f] = a[l];
			a[l] = tmp;
			f++;
			l--;
		}
	}
	if (first < l)
	{
		quicksort(a, first, l);
	}
	if (f < last)
	{
		quicksort(a, f, last);
	}
}

int main()
{
	int n;
	int n1 = 0;
	cin >> n;
	int nf = n - 1;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	cout << "Start array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	quicksort(a, n1, nf);
	cout << "Final array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete[]a;
	return 0;
}