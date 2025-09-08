#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    
    unordered_map<char, int> strToI = {
    	{'I', 1},
    	{'V', 5},
    	{'X', 10},
    	{'L', 50},
    	{'C', 100},
    	{'D', 500},
    	{'M', 1000}
    };
    unordered_map<int, char> iToStr = {
        {1, 'I'},
    	{5, 'V'},
    	{10, 'X'},
    	{50, 'L'},
    	{100, 'C'},
    	{500, 'D'},
    	{1000, 'M'}
    };
    
    int n = 0;
    string str;
    for (int i = 0; i < 2; i++) {
        cin >> str;

        int j;
        for (j = 0; j < str.length() - 1; j++) {
            if (strToI[str[j]] < strToI[str[j + 1]]) {
                n += strToI[str[j + 1]] - strToI[str[j]];
                j++;
            }
            else
                n += strToI[str[j]];
        }

        if (j < str.length())
            n += strToI[str[j]];
     }

    cout << n << "\n";

    for (int i = 1000; i > 0; i /= 10) {
        int temp = n / i;
        
        if (temp == 9 || temp == 4) {
            cout << iToStr[i] << iToStr[(temp + 1) * i];
            n -= temp * i;
            continue;
        }
            
        if (temp >= 5) {
            cout << iToStr[5 * i];
            n -= 5 * i;
            temp -= 5;
        }

        for (int j = 0; j < temp; j++) {
            cout << iToStr[i];
            n -= i; 
        }
    }
    
    return 0;
}