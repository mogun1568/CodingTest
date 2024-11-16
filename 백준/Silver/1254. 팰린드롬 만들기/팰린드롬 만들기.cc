#include <iostream>
#include <string>
using namespace std;

string str;

bool palindrome(int s, int e) {
    s++, e--;
    while (s < e) {
        if (str[s] != str[e])
            return false;

        s++, e--;
    }

    return true;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int idx = str.length() - 1;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str.back()) {
            if (palindrome(i, str.length() - 1)) {
                idx = i;
                break;
            }
        }
    }

    cout << str.length() + idx;
    
    return 0;
}