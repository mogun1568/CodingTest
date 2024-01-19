#include <iostream>

using namespace std;

long long dp[66][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 65; i++) {
        dp[i][0] = 1;

        for (int j = 1; j < 10; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    
    while (t--) {
        cin >> n;

        cout << dp[n + 1][9] << "\n";
    }
    
    return 0;
}