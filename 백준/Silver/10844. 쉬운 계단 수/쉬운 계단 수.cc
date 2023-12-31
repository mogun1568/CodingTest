#include <iostream>

using namespace std;

#define DIV 1000000000
int dp[101][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;

    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % DIV;
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % DIV;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        sum = (sum + dp[n][i]) % DIV;
    }

    cout << sum;

    return 0;
}