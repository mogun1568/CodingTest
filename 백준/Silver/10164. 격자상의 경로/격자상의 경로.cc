#include <iostream>

using namespace std;

int dp[16][16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    dp[1][1] = 1;
    
    if (k != 0) {
        int mid[2] = {k / m + 1, k % m};
        int tmp;

        for (int i = 1; i <= mid[0]; i++) {
            for (int j = 1; j <= mid[1]; j++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1]; 
            }
        }
        tmp = dp[mid[0]][mid[1]];
        dp[mid[0]][mid[1]] = 1;
        
        for (int i = mid[0]; i <= n; i++) {
            for (int j = mid[1]; j <= m; j++) {
                if (i == mid[0] && j == mid[1]) {
                    continue;
                }
                
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1]; 
            }
        }

        cout << tmp * dp[n][m];
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1]; 
            }
        }

        cout << dp[n][m];
    }
    
    return 0;
}