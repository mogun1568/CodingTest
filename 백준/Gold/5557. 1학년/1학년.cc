#include <iostream>
#include <vector>

using namespace std;

long long dp[100][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, num;
    cin >> n >> num;
    dp[1][num] = 1;
    
    for (int i = 2; i < n; i++) {
        cin >> num;

        for (int j = 0; j <= 20; j++) {
            if (j + num <= 20) {
                dp[i][j + num] += dp[i - 1][j];
            }
            if (j - num >= 0) {
                dp[i][j - num] += dp[i - 1][j];
            }
        }
    }
    
    cin >> num;
    cout << dp[n - 1][num];
    
    return 0;
}