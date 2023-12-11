#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s2Len, cnt = 0;
    string s, s2 = "I";
    cin >> n >> m >> s;

    for (int i = 0; i < n; i++) {
        s2 += "OI";
    }
    s2Len = s2.length();

    for (int i = 0; i <= s.length() - s2Len; i++) {
        if (s2 == s.substr(i, s2Len)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}