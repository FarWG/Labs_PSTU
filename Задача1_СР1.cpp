#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int x;
	int a, b, c;
	bool F = false;
	int t;
	cout << "Введите 3-х значное число" << endl;
	cin >> x;
	while ((x < 100) || (x > 999)) {
		cout << "Вы ввели неправильно число, повторите попытку" << endl;
		cin >> x;
	}
	a = x % 10;
	x = x / 10;
	b = x % 10;
	c = x / 10;
	while (F == false) {
		if ((a == b) || (a == c) || (b == c)) {
			cout << "Вы ввели число, в котором повторяются цифры, повторите попытку" << endl;
			cin >> x;
			a = x % 10;
			x = x / 10;
			b = x % 10;
			c = x / 10;
		}
		else {
			F = true;
		}
	}
	cout << "Возможные варианты:" << endl;
	cout << a << b << c << endl;
	t = c;
	c = b;
	b = t;
	cout << a << b << c << endl;
	t = a;
	a = c;
	c = b;
	b = t;
	cout << a << b << c << endl;
	t = c;
	c = b;
	b = t;
	cout << a << b << c << endl;
	t = a;
	a = b;
	b = c;
	c = t;
	cout << a << b << c << endl;
	t = c;
	c = b;
	b = t;
	cout << a << b << c << endl;
	cout << "Максимальное число:" << endl;
	if ((a > b) && (a > c)) {
		if (b > c) {
			cout << a << b << c << endl;
		}
		else {
			cout << a << c << b << endl;
		}
	}
	if ((b > a) && (b > c)) {
		if (a > c) {
			cout << b << a << c << endl;
		}
		else {
			cout << b << c << a << endl;
		}
	}
	if ((c > a) && (c > b)) {
		if (a > b) {
			cout << c << a << b << endl;
		}
		else {
			cout << c << b << a << endl;
		}
	}
	return 0;
}