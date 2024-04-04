#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, result; 
    cin >> n >> a;
    dp[0][0] = a;
    dp[0][1] = a;
    result = a;
    
    for (int i = 1; i < n; i++) {
        cin >> a;
        dp[i][0] = a;
        
        dp[i][0] = max(dp[i][0], dp[i - 1][0] + dp[i][0]);

        if (a < 0) {
            dp[i][1] = max(dp[i - 1][1] + a, dp[i - 1][0]);
        } else {
            dp[i][1] = dp[i - 1][1] + a;
        }

        result = max(result, dp[i][0]);
        result = max(result, dp[i][1]);
    }

    cout << result;
    
    return 0;
}