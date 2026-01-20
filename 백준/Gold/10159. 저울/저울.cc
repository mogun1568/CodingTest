#include <iostream>
using namespace std;

bool scale[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        scale[i][i] = true;
    
    int a, b;
    while (M--) {
        cin >> a >> b;
        scale[a][b] = true; // a가 b보다 무겁다
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (scale[i][k] && scale[k][j])
                    scale[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            // i가 j보다 무겁지 않고 j가 i보다 무겁지 않으면 모르는 상태
            if (!scale[i][j] && !scale[j][i])
                cnt++;
        }

        cout << cnt << "\n";
    }
    
    return 0;
}