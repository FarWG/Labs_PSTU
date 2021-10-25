#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int num, u, i;
	num = rand() % 101;
	i = 0;
	bool f = true;
	while ((i <= 6) && (f == true)) {
		i += 1;
		cout << i << " попытка" << endl;
		cout << "Попытайтесь угадать число:" << endl;
		cin >> u;
		if (u < num) {
			cout << "Данное число меньше, чем загадонное" << endl;
		}
		if (u > num) {
			cout << "Данное число больше, чем загадонное" << endl;
		}
		if (u == num) {
			f = false;
			cout << "Число угадано" << endl;
		}
	}
	if (i == 7) {
		cout << "Попытки закончились" << endl;
	}
	// cout << num;
	return 0;
}

