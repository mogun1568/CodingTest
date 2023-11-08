#include <iostream>
#include <algorithm>

using namespace std;

int wg[10001], dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin >> wg[1] >> wg[2];

    dp[1] = wg[1];
    dp[2] = wg[1] + wg[2];

    for (int i = 3; i <= n; i++) {
        cin >> wg[i];

        // dp[i - 3] + wg[i - 1] + wg[i], dp[i - 2] + wg[i], dp[i - 1] 중에 가장 큰 값
        dp[i] = max(dp[i - 3] + wg[i - 1] + wg[i], max(dp[i - 2] + wg[i], dp[i - 1]));
    }

    cout << dp[n];

    return 0;
}