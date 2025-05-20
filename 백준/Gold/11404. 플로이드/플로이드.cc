#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000000

int city[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, s, e, c;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j)
                city[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        city[s][e] = min(city[s][e], c);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (city[i][j] == INF)
                cout << 0;
            else
                cout << city[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}