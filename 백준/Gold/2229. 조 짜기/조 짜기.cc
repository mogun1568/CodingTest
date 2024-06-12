#include <iostream>
#include <algorithm>

using namespace std;

int N;
int team[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> team[1];

    int minDiff, maxDiff;
    for (int i = 2; i <= N; i++) {
        cin >> team[i];

        minDiff = 10000;
        maxDiff = 0;

        for (int j = i; j > 0; j--) {
            if (team[j] < minDiff)
                minDiff = team[j];
            if (team[j] > maxDiff)
                maxDiff = team[j];

            dp[i] = max(dp[i], dp[j - 1] + maxDiff - minDiff);
        }
    }

    cout << dp[N];
    
    return 0;
}