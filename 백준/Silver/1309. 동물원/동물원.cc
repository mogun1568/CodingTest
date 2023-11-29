#include <iostream>

using namespace std;

#define MOD 9901

int dp[100001] = {1, 3};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[n];

    return 0;
}