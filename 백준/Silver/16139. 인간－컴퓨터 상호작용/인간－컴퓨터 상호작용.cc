#include <iostream>

using namespace std;

int dp[200000][26];
const int alp = 'a';

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (i != 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j == s[i] - alp) {
                dp[i][j]++;
            }
        }
    }

    int q, l, r;
    char a;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;

        int cnt;
        if (l == 0) {
            cnt = dp[r][a - alp];
        } else {
            cnt = dp[r][a - alp] - dp[l - 1][a - alp];
        }
        
        cout << cnt << "\n";
    }

    return 0;
}