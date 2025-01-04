#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int len = s.length();
    bool flag = false;

    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            cout << len;
            return 0;
        }

        if (s[i] != s[i + 1])
            flag = true;
    }

    if (flag)
        cout << len - 1;
    else
        cout << -1;
    
    return 0;
}