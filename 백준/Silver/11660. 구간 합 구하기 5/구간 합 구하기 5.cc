#include <iostream>

using namespace std;

int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dp[i][j];

            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                dp[i][j] += dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            } else {
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }
    }

    int x1, y1, x2, y2, result;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        result = dp[x2][y2];

        if (x1 - 1 > 0) {
            result -= dp[x1 - 1][y2];
        }
        if (y1 - 1 > 0) {
            result -= dp[x2][y1 - 1];
        }
        if (x1 - 1 > 0 && y1 - 1 > 0) {
            result += dp[x1 - 1][y1 - 1];
        }

        cout << result << "\n";
    }
    
    return 0;
}