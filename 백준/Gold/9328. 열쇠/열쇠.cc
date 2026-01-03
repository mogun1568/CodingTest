#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int h, w;
char plan[105][105];
bool visited[105][105];
bool keys[26];
vector<pair<int, int>> doors[26];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void init() {
    memset(visited, false, sizeof(visited));
    memset(keys, false, sizeof(keys));
    for (int i = 0; i < 26; i++)
        doors[i].clear();
}

int BFS() {
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});
    int document = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= h + 2 || nc < 0 || nc >= w + 2)
                continue;            
            
            if (visited[nr][nc])
                continue;

            if (plan[nr][nc] == '*')
                continue;
            else if (plan[nr][nc] == '$') {
                visited[nr][nc] = true;
                q.push({nr, nc});
                document++;
            }
            else if (plan[nr][nc] >= 'a' && plan[nr][nc] <= 'z') {
                visited[nr][nc] = true;
                q.push({nr, nc});
                
                int idx = plan[nr][nc] - 'a';
                if (keys[idx])
                    continue;
                
                keys[idx] = true;
                for (auto pos : doors[idx]) {
                    visited[pos.first][pos.second] = true;
                    q.push(pos);
                }
                doors[idx].clear();
            }
            else if (plan[nr][nc] >= 'A' && plan[nr][nc] <= 'Z') {
                visited[nr][nc] = true;
                
                int idx = plan[nr][nc] - 'A';
                if (keys[idx])
                    q.push({nr, nc});
                else
                    doors[idx].push_back({nr, nc});
            }
            else {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return document;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> h >> w;
        
        string str;
        for (int i = 1; i <= h; i++) {
            cin >> str;
            for (int j = 0; j < w + 2; j++) {
                if (j == 0 || j == w + 1)
                    plan[i][j] = '.';
                else
                    plan[i][j] = str[j - 1];
            }
        }
        for (int i = 0; i < w + 2; i++)
            plan[0][i] = plan[h + 1][i] = '.';

        init();

        string initialKeys;
        cin >> initialKeys;
        if (initialKeys != "0") {
            for (auto key : initialKeys)
                keys[key - 'a'] = true;
        }

        cout << BFS() << "\n";
    }

    return 0;
}