#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (auto i : s)
        alpha[i - 'A']++;

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 1)
            cnt++;
    }
    if (cnt > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    string str = "";
    char c = ' ';
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 1)
            c = i + 'A';

        for (int j = 0; j < alpha[i] / 2; j++)
            str += i + 'A';
    }

    cout << str;
    if (c != ' ')
        cout << c;
    reverse(str.begin(), str.end());
    cout << str;
    
    return 0;
}