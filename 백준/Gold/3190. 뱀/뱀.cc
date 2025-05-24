#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int N;
int board[101][101];
queue<pair<int, int>> dir;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K, r, c;
    cin >> N >> K;
    while (K--) {
        cin >> r >> c;
        board[r][c] = 2;
    }

    int L, X;
    char C;
    cin >> L;
    while (L--) {
        cin >> X >> C;

        if (C == 'L')
            dir.push({X, 3});
        else
            dir.push({X, 1});
    }

    deque<pair<int, int>> dq;
    board[1][1] = 1;
    dq.push_back({1, 1});
    int sec = 0, d = 1;
    
    while (1) {
        sec++;
        
        int nr = dq.front().first + dr[d];
        int nc = dq.front().second + dc[d];

        if (nr < 1 || nr > N || nc < 1 || nc > N)
            break;

        if (board[nr][nc] == 1)
            break;
        else if (board[nr][nc] == 0) {
            board[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        
        board[nr][nc] = 1;
        dq.push_front({nr, nc});

        if (!dir.empty() && sec == dir.front().first) {
            d = (d + dir.front().second) % 4;
            dir.pop();
        }
    }

    cout << sec;
    
    return 0;
}