#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[2001], b[2001];
int dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = N; i > 0; i--) {
        cin >> a[i];
    }
    for (int i = N; i > 0; i--) {
        cin >> b[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);

            if (a[i] > b[j]) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + b[j]);
            }
        }
    }

    cout << dp[N][N];
    
    return 0;
}