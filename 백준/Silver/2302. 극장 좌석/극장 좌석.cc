#include <iostream>

using namespace std;

int dp[41];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, start = 0, vip, result = 1;
    cin >> n >> m;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n - m; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i < m; i++) {
        cin >> vip;

        result *= dp[vip - start - 1];
        start = vip;
    }
    result *= dp[n - start];

    cout << result;
    
    return 0;
}