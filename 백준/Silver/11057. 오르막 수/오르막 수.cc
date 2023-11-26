#include <iostream>

using namespace std;
#define MOD 10007

int dp[1001][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }
            
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += dp[n][i];
    }

    cout << result % MOD;
    
    return 0;
}