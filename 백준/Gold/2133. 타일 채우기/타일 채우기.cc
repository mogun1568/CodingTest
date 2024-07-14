#include <iostream>

using namespace std;

int N;
int dp[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        if (i % 2 != 0)
            dp[i] = 0;
        else {
            for (int j = 2; j <= i; j += 2) {
                if (j == 2) 
                    dp[i] = dp[i - j] * dp[2];
                else 
                    dp[i] += dp[i - j] * 2;
            }
        }
    }
    
    cout << dp[N];

    return 0;
}