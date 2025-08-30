#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string MakePalindrome(string str) {
    int len = str.length();
    string left = str.substr(0, len / 2);
    string mid = len % 2 == 0 ? "" : string(1, str[len / 2]);
    string right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    string palindrome = MakePalindrome(str);
    if (palindrome > str) {
        cout << palindrome;
        return 0;
    }

    int len = str.length();
    int idx = (len - 1) / 2;
    while (str[idx] == '9')
        str[idx--] = '0';

    if (idx < 0) {
        cout << 1;
        while (--len)
            cout << 0;
        cout << 1;
        return 0;
    }
    
    str[idx] += 1;

    cout << MakePalindrome(str);
    
    return 0;
}