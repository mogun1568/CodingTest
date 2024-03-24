#include <iostream>
#include <cstring>

using namespace std;

int coin[20];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }
        cin >> m;

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= m; j++) { 

                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << "\n";

        memset(dp, 0, sizeof(dp));
    }
    
    return 0;
}