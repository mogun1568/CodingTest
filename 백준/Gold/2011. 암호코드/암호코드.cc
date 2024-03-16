#include <iostream>
#include <string>

using namespace std;

int pw[5001];
int dp[5001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int len = s.length();
    for (int i = 1; i <= len; i++) {
        pw[i] = s[i - 1] - '0';
    }

    if (pw[1] == 0) {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    for (int i = 1; i <= len; i++) {
        if (pw[i] > 0 && pw[i] < 10) {
            dp[i] = (dp[i] + dp[i - 1]) % 1000000;
        }

        int temp = pw[i - 1] * 10 + pw[i];
        if (temp >= 10 && temp <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }

    cout << dp[len]; 

    return 0;
}