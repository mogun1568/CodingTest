#include <iostream>
#include <algorithm>

using namespace std;

int sticker[2][100000];
int dp[2][100000];

int test(int n) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sticker[i][j];
        }
    }

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[0][1] + dp[1][0];
    dp[1][1] = sticker[1][1] + dp[0][0];

    for (int i = 2; i < n; i++) {
        dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }

    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << test(n) << "\n";
    }
    
    return 0;
}