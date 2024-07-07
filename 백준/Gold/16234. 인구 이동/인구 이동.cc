#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int N, L, R, sum, answer;
int ground[50][50];
bool visited[50][50];
vector<pair<int, int>> v;
bool check = true;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int Bfs(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    int sum = 0;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        sum += ground[cr][cc];
        v.push_back({cr, cc});

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (visited[nr][nc])
                continue;
            
            if (abs(ground[nr][nc] - ground[cr][cc]) < L || abs(ground[nr][nc] - ground[cr][cc]) > R)
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ground[i][j];
        }
    }

    while (check) {
		check = false;
        memset(visited, false, sizeof(visited));
        
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					sum = Bfs(i, j);
				}

				if (v.size() >= 2) {
					check = true;
					for (int k = 0; k < v.size(); k++) {
						ground[v[k].first][v[k].second] = sum / v.size();
					}
				}
			}
		}

        if (check)
            answer++;
	}

    cout << answer;
    
    return 0;
}