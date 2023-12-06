#include <iostream>

using namespace std;

long long dp[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, dis;
    cin >> n;

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dis;

            if (dp[i][j] == 0 || dis == 0) {
                continue;
            }

            if (i + dis < n) {
                dp[i + dis][j] += dp[i][j];
            }
            if (j + dis < n) {
                dp[i][j + dis] += dp[i][j];
            }
        }
    }
    
    cout << dp[n - 1][n - 1];

    return 0;
}