#include <iostream>
using namespace std;

int DP[201][201];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= K; i++)
        DP[1][i] = i;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++)
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;
    }

    cout << DP[N][K];    

    return 0;
}