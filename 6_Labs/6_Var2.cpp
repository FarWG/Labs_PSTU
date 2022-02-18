#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    string tmp;
    string tmax;
    string tmin;
    int max = 0;
    int min;
    int count = 0;
    getline(cin, text);
    text += ".";
    min = text.size();
    char sim[] = { '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int s = 0;
    while (text[s] != '\0')
    {
        for (int i = 0; i < sizeof(sim); i++)
            {
                if (text[s] == sim[i])
                {
                    count += 1;
                }
                if (count > max) {
                    max = count;
                }
                if (text[s] == ' ' || text[s] == '.')
                {
                    if ((min > count) && (count != 0)) {
                        min = count;
                    }
                    count = 0;
                }
            }
        s += 1;
    }
    cout << max << " " << min << endl;
    count = 0;
    s = 0;
    while (text[s] != '\0')
    {
        for (int i = 0; i < sizeof(sim); i++) {
            if (text[s] == sim[i])
            {
                count += 1;
                tmp += text[s];
            }
            if (max == count) {
                tmax = tmp;
            }
            if (text[s] == ' ' or text[s] == '.')
            {
                if (min == count) {
                    tmin = tmp;
                }
                count = 0;
                tmp.erase(0);
            }
        }
        s += 1;
    }
    cout << "Max: " << tmax << endl;
    cout << "Min: " << tmin << endl;
    return 0;
}