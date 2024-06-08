#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R;

int arr[300][300];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void Rotate(int start, int len) {
    int cnt = R % len;

    while (cnt--) {
        int startValue = arr[start][start];
        int r = start;
        int c = start;

        int k = 0;
        while (k < 4) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr == start && nc == start)
                break;

            if (nr >= start && nr < N - start && nc >= start && nc < M - start) {
                arr[r][c] = arr[nr][nc];
                r = nr;
                c = nc;
            }
            else
                k++;
        }
        
        arr[start + 1][start] = startValue;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = min(N, M) / 2, n = N, m = M;
    for(int i = 0; i < cnt; i++) {
        Rotate(i, 2 * n + 2 * m - 4);
        n -= 2;
        m -= 2;    
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}