#include <iostream>
#include <algorithm>
using namespace std;

int DP[2][100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++)
                cin >> DP[i][j];
        }

        DP[0][1] += DP[1][0];
        DP[1][1] += DP[0][0];

        for (int i = 2; i < N; i++) {
            DP[0][i] += max(DP[1][i - 1], max(DP[0][i - 2], DP[1][i - 2]));
            DP[1][i] += max(DP[0][i - 1], max(DP[0][i - 2], DP[1][i - 2]));
        }

        cout << max(DP[0][N - 1], DP[1][N - 1]) << "\n";
    }
    
    return 0;
}