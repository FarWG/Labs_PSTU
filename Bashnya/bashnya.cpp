#include <iostream>

using namespace std;

int bashnya(int n, int st, int fnl, int tmp)
{
	if (n > 0)
	{
		bashnya(n - 1, st, tmp, fnl);
		cout << st << " => " << fnl << endl;
		bashnya(n - 1, tmp, fnl, st);
	}
	return 0;
}

int main()
{
	int n; // Кол-во дисков
	cin >> n;
	bashnya(n, 1, 2, 3);
	return 0;
}