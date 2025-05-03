#include <iostream>
using namespace std;

int DP[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> DP[i][j];

            DP[i][j] += DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2, ans;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        ans = DP[x2][y2] - DP[x1 - 1][y2] - DP[x2][y1 - 1] + DP[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
    
    return 0;
}