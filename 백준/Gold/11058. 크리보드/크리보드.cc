#include <iostream>

using namespace std;

int N;
long long dp[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
        
		for (int j = 3; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}

    cout << dp[N];
    
    return 0;
}