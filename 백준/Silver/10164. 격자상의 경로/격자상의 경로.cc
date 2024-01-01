#include <iostream>

using namespace std;

int dp[16][16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1]; 
        }
    }

    if (k == 0) {
         cout << dp[n][m];
    } else {
        int r, c;

        if (k % m == 0) {
            r = k / m;
            c = m;
        } else {
            r = k / m + 1;
            c = k % m;
        }

        cout << dp[r][c] * dp[n - r + 1][m - c + 1];
    }
    
    return 0;
}