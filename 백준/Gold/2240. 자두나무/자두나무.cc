#include <iostream>
#include <algorithm>

using namespace std;

int list[1001];
int dp[31][3][1001];
// dp[이동횟수][현재위치][시간]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, w, answer = 0;
	cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        cin >> list[i];
    }

    for (int i = 0; i <= w; i++) {
        for (int j = 1; j <= t; j++) {
            if (i == 0) {
                dp[i][1][j] = dp[i][1][j - 1] + (list[j] == 1);
                continue;
            }

            dp[i][1][j] = max(dp[i][1][j - 1] + (list[j] == 1), dp[i - 1][2][j - 1] + (list[j] == 1));
            dp[i][2][j] = max(dp[i][2][j - 1] + (list[j] == 2), dp[i - 1][1][j - 1] + (list[j] == 2));
        }
    }

    for (int i = 0; i <= w; i++) {
        for (int j = 1; j <= 2; j++) {
            answer = max(answer, dp[i][j][t]);
        }
    }

    cout << answer;
}