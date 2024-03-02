#include <iostream>

using namespace std;

bool house[17][17];
int dp[17][17][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }

    dp[1][2][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (house[i][j]) {
                continue;
            }

            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

            if (house[i - 1][j] || house[i][j - 1]) {
                continue;
            }

            dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

    return 0;
}