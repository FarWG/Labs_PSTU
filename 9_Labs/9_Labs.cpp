#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string tmp;
    fstream F1("F1.txt", ios::in);
    fstream F2("F2.txt", ios::out);
    while (getline(F1, tmp))
    {
        if (tmp.front() == 'А')
        {
            F2 << tmp << endl;
        }   
    }
    F1.close();
    F2.close();
    return 0;
}