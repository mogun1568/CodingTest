#include <iostream>
#include <algorithm>

using namespace std;

#define INF 500

int N, M, ans;
int fw1[501][501];
int fw2[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fw1[i][j] = INF;
            if (i == j) fw1[i][j] = 0;
            fw2[i][j] = INF;
            if (i == j) fw2[i][j] = 0;
        }
    }
    
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        fw1[a][b] = 1;
        fw2[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (fw1[i][k] + fw1[k][j] < fw1[i][j])
                    fw1[i][j] = fw1[i][k] + fw1[k][j];
                if (fw2[i][k] + fw2[k][j] < fw2[i][j])
                    fw2[i][j] = fw2[i][k] + fw2[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (fw1[i][j] != INF || fw2[i][j] != INF)
                cnt++;
        }

        if (cnt == N)
            ans++;
    }
    
    cout << ans;
    
    return 0;
}