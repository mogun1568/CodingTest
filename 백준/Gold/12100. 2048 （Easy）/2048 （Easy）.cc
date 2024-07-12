#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, answer;
int board[20][20];

void Move(int d) {
    queue<int> q;
    
    switch (d) {
        case 0: // left
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != 0) {
                        q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                }

                int idx = 0;
                while (!q.empty()) {
                    int b = q.front();
                    q.pop();

                    if (board[i][idx] == 0)
                        board[i][idx] = b;
                    else if (board[i][idx] == b) {
                        board[i][idx]*= 2;
                        idx++;
                    }
                    else {
                        idx++;
                        board[i][idx] = b;
                    }
                }
            }
            break;
        case 1: // up
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[j][i] != 0) {
                        q.push(board[j][i]);
                        board[j][i] = 0;
                    }
                }

                int idx = 0;
                while (!q.empty()) {
                    int b = q.front();
                    q.pop();

                    if (board[idx][i] == 0)
                        board[idx][i] = b;
                    else if (board[idx][i] == b) {
                        board[idx][i] *= 2;
                        idx++;
                    }
                    else {
                        idx++;
                        board[idx][i] = b;
                    }
                }
            }
            break;
        case 2: // right
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j >= 0; j--) {
                    if (board[i][j] != 0) {
                        q.push(board[i][j]);
                        board[i][j] = 0;
                    } 
                }

                int idx = N - 1;
                while (!q.empty()) {
                    int b = q.front();
                    q.pop();

                    if (board[i][idx] == 0)
                        board[i][idx] = b;
                    else if (board[i][idx] == b) {
                        board[i][idx] = b * 2;
                        idx--;
                    }
                    else {
                        idx--;
                        board[i][idx] = b;
                    }
                }
            }
            break;
        case 3: // down
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j >= 0; j--) {
                    if (board[j][i] != 0) {
                        q.push(board[j][i]);
                        board[j][i] = 0;
                    } 
                }

                int idx = N - 1;
                while (!q.empty()) {
                    int b = q.front();
                    q.pop();

                    if (board[idx][i] == 0)
                        board[idx][i] = b;
                    else if (board[idx][i] == b) {
                        board[idx][i] *= 2;
                        idx--;
                    }
                    else {
                        idx--;
                        board[idx][i] = b;
                    }
                }
            }
            break;   
    }
}

void Dfs(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer = max(answer, board[i][j]);
            }
        }

        return;
    }

    int temp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = board[i][j];
        }
    }

    for (int k = 0; k < 4; k++) {
        Move(k);
        Dfs(cnt + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    Dfs(0);

    cout << answer;
    
    return 0;
}