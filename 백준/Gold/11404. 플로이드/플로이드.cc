#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 987654321

int N, M, a, b, c;

int city[101][101];

void Floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            city[i][j] = MAX;
        }
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c);
    }

    Floyd();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (city[i][j] == MAX)
                cout << "0 ";
            else
                cout << city[i][j] << " ";
        }
        cout << "\n";
    }    
    
    return 0;
}