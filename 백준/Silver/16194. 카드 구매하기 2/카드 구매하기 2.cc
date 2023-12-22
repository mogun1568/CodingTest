#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i];

        for (int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[n];
    
    return 0;
}