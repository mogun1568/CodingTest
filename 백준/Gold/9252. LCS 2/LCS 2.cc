#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int r = s1.length(), c = s2.length();
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[r][c] << "\n";
    if (dp[r][c] == 0)
        return 0;

    string LCS;
	while (dp[r][c]) {
		if (dp[r][c] == dp[r - 1][c])
			r--;
		else if (dp[r][c] == dp[r][c - 1])
			c--;
		else {
            LCS = s1[r - 1] + LCS;
			r--, c--;
        }
	}

    cout << LCS;
    
    return 0;
}