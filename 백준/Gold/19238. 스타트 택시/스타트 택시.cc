#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Info {
    int r, c;
    int dist;
};

int N, fuel;
int grid[21][21];
bool visited[21][21];
pair<int, int> destination[401];
int tr, tc;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool cmp(const Info& a, const Info& b) {
    if (a.dist == b.dist) {
        if (a.r == b.r)
            return a.c < b.c;
        return a.r < b.r;
    }
    return a.dist < b.dist;  
}

bool moveToDest(int r, int c) {
    memset(visited, false, sizeof(visited));
    queue<Info> q;
    visited[r][c] = true;
    q.push({r, c, 0});

    int num = grid[r][c];
    grid[r][c] = 0;
    
    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int dist = q.front().dist;
        q.pop();

        if (dist > fuel)
            return false;
        
        if (cr == destination[num].first && cc == destination[num].second) {
            fuel += dist;
            tr = cr;
            tc = cc;
            return true;
        } 
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N)
                continue;

            if (grid[nr][nc] == -1)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc, dist + 1});
        }
    }

    return false;
}

bool findPassenger() {
    memset(visited, false, sizeof(visited));
    vector<Info> passengers;
    queue<Info> q;
    visited[tr][tc] = true;
    q.push({tr, tc, 0});

    int minDist = 2e9;
    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int dist = q.front().dist;
        q.pop();

        if (dist > minDist)
            break;
        
        if (dist > fuel)
            continue;

        if (grid[cr][cc] > 0) {
            minDist = dist;
            passengers.push_back({cr, cc, dist});
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N)
                continue;

            if (grid[nr][nc] == -1)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc, dist + 1});
        }
    }

    if (passengers.empty())
        return false;

    if (passengers.size() > 1)
        sort(passengers.begin(), passengers.end(), cmp);

    fuel -= passengers[0].dist;
    return moveToDest(passengers[0].r, passengers[0].c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M;
    cin >> N >> M >> fuel;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
                grid[i][j] = -1;
        }
    }

    cin >> tr >> tc;

    int sr, sc;
    for (int i = 1; i <= M; i++) {
        cin >> sr >> sc >> destination[i].first >> destination[i].second;
        grid[sr][sc] = i;
    }

    while (M--) {
        if (!findPassenger()) {
            cout << -1;
            return 0;
        }
    }

    cout << fuel;
    
    return 0;
}