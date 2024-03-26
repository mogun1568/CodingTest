#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int l, r, c;
int buliding[30][30][30];
int s[3];
int e[3];

struct lc {
    int l, r, c;
};

int dl[6] = {0, 0, 0, 0, -1, 1};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {1, -1, 0, 0, 0, 0};

bool bfs() {
    buliding[s[0]][s[1]][s[2]] = 1;
    queue<lc> q;
    q.push({s[0], s[1], s[2]});

    while (!q.empty()) {
        int cl = q.front().l;
        int cr = q.front().r;
        int cc = q.front().c;
        q.pop();

        if (cl == e[0] && cr == e[1] && cc == e[2]) {
            return true;
        }

        for (int i = 0; i < 6; i++) {
            int nl = cl + dl[i];
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nl < 0 || nl >= l || nr < 0 || nr >= r || nc < 0 || nc >= c) {
                continue;
            }

            if (buliding[nl][nr][nc] == 0) {
                buliding[nl][nr][nc] = buliding[cl][cr][cc] + 1;
                q.push({nl, nr, nc});
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) {
            break;
        }

        string str;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> str;
                for (int k = 0; k < c; k++) {
                    if (str[k] == '#') {
                        buliding[i][j][k] = -1;
                    } else if (str[k] == 'S') {
                        s[0] = i;
                        s[1] = j;
                        s[2] = k;
                    } else if (str[k] == 'E') {
                        e[0] = i;
                        e[1] = j;
                        e[2] = k;
                    }
                }
            }
        }
        
        if (bfs()) {
            cout << "Escaped in " << buliding[e[0]][e[1]][e[2]] - 1 << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }

        memset(buliding, 0, sizeof(buliding));
    }
    
    return 0;
}