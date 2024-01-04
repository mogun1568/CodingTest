#include <iostream>

using namespace std;

int board[20][20];
bool visit[20][20][3][2];
int resultColor;
int coor[2];

// 우, 하, 우하, 우상
int dr[4] = {0, 1, 1, -1};
int dc[4] = {1, 0, 1, 1};

void check(int r, int c, int color) {
    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            if (visit[r][c][i][color]) {
                continue;
            }
            visit[r][c][i][color] = true;
        }
        
        int cnt = 1;
        int nr = r;
        int nc = c;
        
        while (1) {
            nr += dr[i];
            nc += dc[i];
            
            if (nr < 1 || nr > 19 || nc > 19) {
                break;
            }

            if (board[nr][nc] != color) {
                break;    
            }


            if (i < 3) {
                visit[nr][nc][i][color] = true;
            }
            cnt++;
        }

        if (i == 3) {
            nr = r;
            nc = c;
            
            while (1) {
                nr += 1;
                nc += -1;

                if (nr > 19 && nc < 1) {
					nr--;
					nc++;
                    break;
                }
                
                if (board[nr][nc] != color) {
					nr--;
					nc++;
                    break;
                } 

                cnt++;
            }
        }

        if (cnt == 5) {
            if (resultColor != 0) {
                resultColor = -1;
                return;
            }

            resultColor = color;
            if (i < 3) {
                coor[0] = r;
                coor[1] = c;
            } else {
                coor[0] = nr;
                coor[1] = nc;
            }
            
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (board[i][j] != 0 && board[i][j] != resultColor) {
                if (board[i][j] == 1) {
                    check(i, j, 1);
                } else if (board[i][j] == 2) {
                    check(i, j, 2);
                }

                if (resultColor == -1) {
                    cout << 0;
                    return 0;
                }
            }
        }
    }

    if (resultColor < 1) {
        cout << 0;
        return 0;
    }
    
    cout << resultColor << "\n";
    cout << coor[0] << " " << coor[1];
    
    return 0;
}