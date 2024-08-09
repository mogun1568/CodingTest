#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2, lcs;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    int r = s1.length();
	int c = s2.length();
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[r][c];
    if (len == 0) {
        cout << 0;
        return 0;
    }
    else
        cout << dp[r][c] << "\n";

	while (dp[r][c]) {
		if (dp[r][c] == dp[r - 1][c])
			r--;
		else if (dp[r][c] == dp[r][c - 1])
			c--;
		else {
            lcs = s1[r - 1] + lcs;
			r--, c--;
        }
	}

    cout << lcs;
    
    return 0;
}