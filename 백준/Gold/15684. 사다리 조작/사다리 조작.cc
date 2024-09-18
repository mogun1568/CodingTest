#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int N, M, H, answer = -1;
bool ladder[31][11];

bool Check() {
    for (int i = 1; i <= N; i++) {
        int cur = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][cur])
                cur++;
            else if (ladder[j][cur - 1])
                cur--;
        }
        
        if (cur != i)
            return false;
    }

    return true;
}

void Dfs(int idx, int cnt, int maxCnt) {
    if (cnt == maxCnt) {
        if (Check()) {
            answer = cnt;
        }

        return;
    } 

    for (int i = idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1])
                continue;

            ladder[i][j] = true;
            Dfs(i, cnt + 1, maxCnt);
            ladder[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> H;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ladder[a][b] = true;
    }

    for (int i = 0; i < 4; i++) {
        if (answer != -1)
            continue;
        
        Dfs(1, 0, i);
    }    

    cout << answer;
    
    return 0;
}