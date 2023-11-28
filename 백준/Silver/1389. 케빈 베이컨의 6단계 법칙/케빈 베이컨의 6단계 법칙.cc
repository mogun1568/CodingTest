#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100

int rel[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                rel[i][j] = 0;
                continue;
            }

            rel[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        rel[a][b] = 1;
        rel[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                rel[i][j] = min(rel[i][j], rel[i][k] + rel[k][j]);
            }
        }
    }

    int result, minSum = 10000;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += rel[i][j];
        }

        if (sum < minSum) {
            minSum = sum;
            result = i;
        }
    }

    cout << result;

    return 0;
}