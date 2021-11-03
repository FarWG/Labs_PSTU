#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int h, m, s;
	int h1, m1, s1;
	int ah, am, as;
	cout << "Введите время начала промежутка:" << endl;
	cin >> h >> m >> s;
	cout << "Введите время конца промежутка:" << endl;
	cin >> h1 >> m1 >> s1;
	ah = (((h1 * 3600) + (m1 * 60) + s1) - ((h * 3600) + (m * 60) + s)) / 3600;
	am = ((((h1 * 3600) + (m1 * 60) + s1) - ((h * 3600) + (m * 60) + s)) / 60) % 60;
	as = (((h1 * 3600) + (m1 * 60) + s1) - ((h * 3600) + (m * 60) + s)) % 60;
	cout << "Время промежутка:" << endl;
	cout << ah << " часа(ов) " << am << " минут(а) " << as << " секунд(а) ";
}