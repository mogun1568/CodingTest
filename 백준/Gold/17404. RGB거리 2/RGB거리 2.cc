#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1001

int N, answer = 1000001;
int house[1000][3];
int dp[1000][3];

void RGB(int idx) {
    for (int i = 0; i < 3; i++) {
        if (i == idx)
            dp[0][i] = house[0][i];
        else
            dp[0][i] = INF;
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    for (int i = 0; i < 3; i++) {
        if (i != idx)
            answer = min(answer, dp[N - 1][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> house[i][0] >> house[i][1] >> house[i][2];

    for (int i = 0; i < 3; i++)
        RGB(i);

    cout << answer;
    
    return 0;
}