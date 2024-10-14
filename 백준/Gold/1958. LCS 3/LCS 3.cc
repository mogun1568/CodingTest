#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2, s3;
int dp[101][101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s1 >> s2 >> s3;

    int a = s1.length();
    int b = s2.length();
    int c = s3.length();

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1] && s2[j - 1] == s3[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }

    cout << dp[a][b][c];
    
    return 0;
}