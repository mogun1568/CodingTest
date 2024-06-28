#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int board[101][101];
queue<pair<int, int>> dir;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int Solve() {
    queue<pair<int, int>> q;
    board[1][1] = 1;
    q.push({1, 1});
    
    int d = 0, sec = 0;
    while (true) {
        int nr = q.back().first + dr[d];
        int nc = q.back().second + dc[d];

        if (nr < 1 || nr > N || nc < 1 || nc > N)
            break;

        if (board[nr][nc] == 1)
            break;

        bool isApple = false;
        if (board[nr][nc] == 2)
            isApple = true;
        
        board[nr][nc] = 1;
        q.push({nr, nc});
                
        if (!isApple) {
            board[q.front().first][q.front().second] = 0;
            q.pop();
        }

        sec++;
        if (dir.front().first == sec) {
            d = (d + dir.front().second) % 4;
            dir.pop();
        }
    }
    
    return sec + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, X;
    char C;
    
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        board[a][b] = 2;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X >> C;
        if (C == 'L')
            dir.push({X, 3});
        else
            dir.push({X, 1});
    }

    cout << Solve();
    
    return 0;
}