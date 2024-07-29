#include <iostream>

using namespace std;

int N, M;
int citys[201][201];
int travel[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> citys[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> travel[i];
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (citys[i][j] == 1)
                    continue;

                if (i == j)
                    citys[i][j] = 1;

                if (citys[i][k] == 1 && citys[k][j] == 1)
                    citys[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < M; i++) {
        if (citys[travel[i - 1]][travel[i]] == 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    
    return 0;
}