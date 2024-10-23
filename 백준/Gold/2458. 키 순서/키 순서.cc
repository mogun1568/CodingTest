#include <iostream>
#include <algorithm>

using namespace std;

#define INF 500

int N, M, ans;
int fw[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fw[i][j] = INF;
            if (i == j) fw[i][j] = 0;
        }
    }
    
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        fw[a][b] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (fw[i][k] + fw[k][j] < fw[i][j])
                    fw[i][j] = fw[i][k] + fw[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (fw[i][j] != INF || fw[j][i] != INF)
                cnt++;
        }

        if (cnt == N)
            ans++;
    }
    
    cout << ans;
    
    return 0;
}