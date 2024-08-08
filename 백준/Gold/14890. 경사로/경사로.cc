#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int N, L, answer;
int map[100][100];
bool visited[100][100];

bool RowCheck(int r) {
    bool temp[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = visited[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    
    for (int i = 1; i < N; i++) {
        if (abs(map[r][i - 1] - map[r][i]) > 1)
            return false;

        if (map[r][i - 1] - map[r][i] == 1) {
            if (i - 1 + L > N)
                return false;
            
            for (int j = i; j < i + L; j++) {
                if (map[r][j] != map[r][i] || temp[r][j])
                    return false;

                temp[r][j] = true;
                q.push({r, j});
            }
            i += L - 1;
        }
        else if (map[r][i - 1] - map[r][i] == -1) {
            if (i - L < 0)
                return false;
            
            for (int j = i - 1; j >= i - L; j--) {
                if (map[r][j] != map[r][i - 1] || temp[r][j]) 
                    return false;

                temp[r][j] = true;
                q.push({r, j});
            }
        }
    }

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        visited[cr][cc] = true;
    }

    return true;
}

bool ColumnCheck(int c) {
    bool temp[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = visited[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    
    for (int i = 1; i < N; i++) {
        if (abs(map[i - 1][c] - map[i][c]) > 1)
            return false;

        if (map[i - 1][c] - map[i][c] == 1) {
            if (i - 1 + L > N)
                return false;
            
            for (int j = i; j < i + L; j++) {
                if (map[j][c] != map[i][c] || temp[j][c])
                    return false;

                temp[j][c] = true;
                q.push({j, c});
            }
            i += L - 1;
        }
        else if (map[i - 1][c] - map[i][c] == -1) {
            if (i - L < 0)
                return false;
            
            for (int j = i - 1; j >= i - L; j--) {
                if (map[j][c] != map[i - 1][c] || temp[j][c])
                    return false;

                temp[j][c] = true;
                q.push({j, c});
            }
        }
    }

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        visited[cr][cc] = true;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (RowCheck(i)) answer++;
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        if (ColumnCheck(i)) answer++;
    }

    cout << answer;
    
    return 0;
}