#include <iostream>

using namespace std;

int dp[51][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, m, d;
    bool check = false;
    cin >> n >> s >> m >> d;

    if (s - d >= 0) {
        dp[1][s - d] = true;
        check = true;
    } 
    if (s + d <= m) {
        dp[1][s + d] = true;
        check = true;
    }
    if (!check) {
        cout << -1;
        return 0;
    }
    
    for (int i = 2; i <= n; i++) {
        cin >> d;
        check = false;
        
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j - d >= 0) {
                    dp[i][j - d] = true;
                    check = true;
                }
                if (j + d <= m) {
                    dp[i][j + d] = true;
                    check = true;
                }
            }
        }

        if (!check) {
            cout << -1;
            return 0;
        }
    }

    for (int i = m; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i;
            break;
        }
    }
    
    return 0;
}