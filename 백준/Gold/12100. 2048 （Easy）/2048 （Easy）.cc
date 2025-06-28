#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, ans;
int board[20][20];

void Move(int d) {
    queue<int> q;
    
    switch (d) {
        case 0: // 상
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < N; i++) {
                    if (board[i][j] != 0) {
                        q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                }
                    

                int idx = 0;
                while (!q.empty()) {
                    int block = q.front();
                    q.pop();

                    if (board[idx][j] == 0)
                        board[idx][j] = block;
                    else if (board[idx][j] == block)
                        board[idx++][j] *= 2;
                    else
                        board[++idx][j] = block;
                }
            }
            break;
        case 1: // 하
            for (int j = 0; j < N; j++) {
                for (int i = N - 1; i >= 0; i--) {
                    if (board[i][j] != 0) {
                        q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                }

                int idx = N - 1;
                while (!q.empty()) {
                    int block = q.front();
                    q.pop();

                    if (board[idx][j] == 0)
                        board[idx][j] = block;
                    else if (board[idx][j] == block)
                        board[idx--][j] *= 2;
                    else
                        board[--idx][j] = block;
                }
            }
            break;
        case 2: // 좌
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != 0) {
                        q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                }

                int idx = 0;
                while (!q.empty()) {
                    int block = q.front();
                    q.pop();

                    if (board[i][idx] == 0)
                        board[i][idx] = block;
                    else if (board[i][idx] == block)
                        board[i][idx++] *= 2;
                    else
                        board[i][++idx] = block;
                }
            }
            break;
        default: // 우
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j >= 0; j--) {
                    if (board[i][j] != 0) {
                        q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                }

                int idx = N - 1;
                while (!q.empty()) {
                    int block = q.front();
                    q.pop();

                    if (board[i][idx] == 0)
                        board[i][idx] = block;
                    else if (board[i][idx] == block)
                        board[i][idx--] *= 2;
                    else
                        board[i][--idx] = block;
                }
            }
    }
}

void DFS(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                ans = max(ans, board[i][j]);
        }

        return;
    }
    
    int temp[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            temp[i][j] = board[i][j];
    }

    for (int k = 0; k < 4; k++) {
        Move(k);
        DFS(cnt + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                board[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    DFS(0);

    cout << ans;
    
    return 0;
}