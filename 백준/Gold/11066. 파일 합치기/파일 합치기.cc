#include <iostream>
#include <algorithm>

using namespace std;

int T, K;
int sum[501];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> sum[i];
            sum[i] += sum[i - 1];
        } 

        for (int c = 1; c <= K; c++) { // 계산해야하는 개수
            for (int i = 1; i <= K - c; i++) {
                int j = i + c;
                dp[i][j] = 987654321;
                
                for (int mid = i; mid < j; mid++) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + (sum[j] - sum[i - 1]));
                }
            }
        }

        cout << dp[1][K] << "\n";
    }
    return 0;
}