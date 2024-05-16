#include <iostream>
#include <algorithm>

using namespace std;

int N, T, K, S;
int dp[10001];

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> T;
    
	for (int i = 0; i < N; i++) {
		cin >> K >> S;
        
		for (int j = T; j >= K; j--) {
			dp[j] = max(dp[j], dp[j - K] + S);
		}
	}
    
	cout << dp[T];
}