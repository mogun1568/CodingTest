#include <iostream>
#include <string>

using namespace std;

int T, K, N, D, answer;
int saw[1001][8];
int twelve[1001];

void Dfs(int n, int d, int lr) {
    if (lr == -1) {
        if (n < 1)
            return;
        
        if (saw[n][(twelve[n] + 6) % 8] != saw[n - 1][(twelve[n - 1] + 2) % 8]) {
            Dfs(n - 1, d * -1, lr);
        }
    }
    else {
        if (n > T)
            return;
            
        if (saw[n][(twelve[n] + 2) % 8] != saw[n + 1][(twelve[n + 1] + 6) % 8]) {
            Dfs(n + 1, d * -1, lr);
        } 
    }
    
    if (n == N) {
        return;
    }

    if (d == 1) {
        twelve[n] = (twelve[n] + 7) % 8;
    }
    else {
        twelve[n] = (twelve[n] + 1) % 8;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            saw[i][j] = s[j];
        }
    }
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> N >> D;

        Dfs(N, D, -1);
        Dfs(N, D, 1);
        
        if (D == 1) {
            twelve[N] = (twelve[N] + 7) % 8;
        }
        else {
            twelve[N] = (twelve[N] + 1) % 8;
        }
    }

    for (int i = 1; i <= T; i++) {
        if (saw[i][twelve[i]] == '1') {
            answer++;
        }
    }

    cout << answer;
    
    return 0;
}