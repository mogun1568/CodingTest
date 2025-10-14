#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[10][10];
vector<pair<int, pair<int, int>>> island;
int parent[7];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void BFS(int r, int c, int num) {
    queue<pair<int, int>> q;
    map[r][c] = num;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            
            if (map[nr][nc] != -1)
                continue;

            map[nr][nc] = num;
            q.push({nr, nc});
        }
    }
}

void MakeRoad(int r, int c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 10; j++) {
            int nr = r + dr[i] * j;
            int nc = c + dc[i] * j;
    
            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                break;
    
            if (map[nr][nc] == map[r][c])
                break;
                
            if (map[nr][nc] == 0)
                continue;
 
            if (j <= 2)
                break;

            int a = map[r][c];
            int b = map[nr][nc];
            island.push_back({j - 1, {a, b}});

            break; 
        }
    }
}

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);
    
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    int islandNum = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == -1) {
                BFS(i, j, islandNum);
                islandNum++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0)
                MakeRoad(i, j);
        }
    }
    sort(island.begin(), island.end());

    for (int i = 1; i < 7; i++)
        parent[i] = i;

    int ans = 0, num = 1;
    for (int i = 0; i < island.size(); i++) {
        int a = island[i].second.first;
        int b = island[i].second.second;
        int c = island[i].first;
        
        if (Find(a) != Find(b)) {
            Merge(a, b);
            ans += c;
            num++;
        }
    }

    if (num == islandNum - 1)
        cout << ans;
    else
        cout << -1;
    
    return 0;
}