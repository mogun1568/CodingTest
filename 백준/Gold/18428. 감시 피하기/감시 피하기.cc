#include <iostream>
#include <vector>

using namespace std;

int n;
char hallway[6][6];
vector<pair<int, int>> blank;
vector<pair<int, int>> teacher;
bool flag;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isPossible() {
    for (int i = 0; i < teacher.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int r = teacher[i].first;
            int c = teacher[i].second;
            int nr = r, nc = c;

            while (1) {
                nr += dr[j];
                nc += dc[j];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                    break;
                }

                if (hallway[nr][nc] == 'O') {
                    break;
                }

                if (hallway[nr][nc] == 'S') {
                    return false;
                }
            }
        }
    }

    return true;
}

void Dfs(int idx, int cnt) {
    if (flag) {
        return;
    }
    
    if (cnt == 3) {
        if (isPossible()) {
            flag = true;
        }
        return;
    }

    for (int i = idx; i < blank.size(); i++) {
        int r = blank[i].first;
        int c = blank[i].second;

        hallway[r][c] = 'O';
        Dfs(i + 1, cnt + 1);
        hallway[r][c] = 'X';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> hallway[i][j];

            if (hallway[i][j] == 'X') {
                blank.push_back({i, j});
            }
            if (hallway[i][j] == 'T') {
                teacher.push_back({i, j});
            }
        }
    }

    Dfs(0, 0);

    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}