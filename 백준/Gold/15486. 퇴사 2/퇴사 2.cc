#include <iostream>
#include <algorithm>

using namespace std;

int dp[1500002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t, p, cur = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t >> p;

        cur = max(cur, dp[i]);

        if (i + t > n + 1) {
            continue;
        }
        
        dp[i + t] = max(dp[i + t], cur + p);
    }
    cur = max(cur, dp[n + 1]);

    cout << cur;
    
    return 0;
}