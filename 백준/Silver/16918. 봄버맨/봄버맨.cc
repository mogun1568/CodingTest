#include <iostream>
#include <string>
#include <queue>

using namespace std;

int r, c;
char board[200][200];
queue<pair<int, int>> q;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void adjacency() {
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        board[cr][cc] = '.';
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
    
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                continue;
            }
    
            board[nr][nc] = '.';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> r >> c >> n;

    string s;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            board[i][j] = s[j];
        }
    }

    if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << 'O';
            }
            cout << "\n";
        }

        return 0 ;
    }

    for (int k = 3; k <= n; k += 2) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    q.push({i, j});
                } else {
                    board[i][j] = 'O';
                }
            }
        }

        adjacency();
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}