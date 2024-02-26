#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, v;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[i] = 10001;
    }

    while (n--) {
        cin >> v;

        for (int i = v; i <= k; i++) {
            dp[i] = min(dp[i], dp[i - v] + 1);
        }
    }

    if (dp[k] == 10001) {
        cout << -1;
    } else {
        cout << dp[k];
    }

    return 0;
}