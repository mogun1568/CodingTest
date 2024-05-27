#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, A, B, M;
int seq[20];
int dp[20][21][21];

int Dfs(int idx, int a, int b) {
    if (idx >= M) {
        return 0;
    }

    if (dp[idx][a][b] != 0) {
        return dp[idx][a][b];
    }

    int c = seq[idx];
    dp[idx][a][b] = min(abs(c - a) + Dfs(idx + 1, c, b), abs(c - b) + Dfs(idx + 1, a, c));

    return dp[idx][a][b];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> A >> B >> M;
    for (int i = 0; i < M; i++) {
        cin >> seq[i];
    }

    cout << Dfs(0, A, B);

    
    return 0;
}