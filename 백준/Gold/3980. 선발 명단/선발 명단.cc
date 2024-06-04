#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int C, answer;
int player[11][11];
bool visited[11];

void Dfs(int idx, int sum) {
    if (idx >= 11) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (player[idx][i] == 0) {
            continue;
        }

        if (visited[i]) {
            continue;
        }
        
        visited[i] = true;
        Dfs(idx + 1, sum + player[idx][i]);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> C;

    while (C--) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> player[i][j];
            }
        }

        answer = 0;
        memset(visited, false, sizeof(visited));
        
        Dfs(0, 0);
        
        cout << answer << "\n";
    }
    
    return 0;
}