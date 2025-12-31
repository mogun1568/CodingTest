#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int disk[50][50];
bool visited[50][50];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void rotateDisk(int x, int d, int k) {
    int temp[50];
    for (int i = x - 1; i < N; i += x) {
        memset(temp, 0, sizeof(temp));
        
        if (d == 0) { // 시계
            for (int j = 0; j < M; j++) {
                int idx = (j + k) % M;
                temp[idx] = disk[i][j];
            }
        }
        else { // 반시계
            for (int j = 0; j < M; j++) {
                int idx = (j + k) % M;
                temp[j] = disk[i][idx];
            }
        }

        for (int j = 0; j < M; j++)
            disk[i][j] = temp[j];
    }
}

bool checkSame(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    bool flag = false;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = (cc + dc[i] + M) % M;

            if (nr < 0 || nr >= N)
                continue;

            if (disk[nr][nc] != disk[r][c])
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
            flag = true;
        }
    }

    if (!flag) {
        visited[r][c] = false;
        return false;
    }

    return true;
}

void eraseNum() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j])
                disk[i][j] = 0;
        }
    }
}

void averageDisk() {
    int sum = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (disk[i][j] == 0)
                continue;
            
            sum += disk[i][j];
            cnt++;
        }
    }

    if (cnt == 0)
        return;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (disk[i][j] == 0)
                continue;
            
            if (disk[i][j] * cnt > sum)
                disk[i][j]--;
            else if (disk[i][j] * cnt < sum)
                disk[i][j]++;      
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> N >> M >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> disk[i][j];
    }

    int x, d, k;
    while (T--) {
        cin >> x >> d >> k;
        
        rotateDisk(x, d, k);

        memset(visited, false, sizeof(visited));
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (disk[i][j] == 0)
                    continue;
                
                if (visited[i][j])
                    continue;

                if (checkSame(i, j))
                    flag = true;
            }
        }

        if (flag)
            eraseNum();
        else
            averageDisk();
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            ans += disk[i][j];
    }

    cout << ans;
    
    return 0;
}