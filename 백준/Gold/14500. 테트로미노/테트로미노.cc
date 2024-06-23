#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, answer;
int paper[500][500];
bool visited[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Solve(int r, int c) {
    vector<int> v;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        v.push_back(paper[nr][nc]);
    }

    if (v.size() < 3)
        return;

    int sum = paper[r][c];
    for (int i = 0; i < v.size(); i++)
        sum += v[i];

    if (v.size() == 3) {
        answer = max(answer, sum);
        return;
    }

    answer = max(answer, sum - *min_element(v.begin(), v.end()));
}

void Dfs(int r, int c, int cnt, int sum) {
    if (cnt == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        if (visited[nr][nc] != 0)
            continue;

        visited[nr][nc] = true;
        Dfs(nr, nc, cnt + 1, sum + paper[nr][nc]);
        visited[nr][nc] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            Dfs(i, j, 1, paper[i][j]);
            visited[i][j] = false;

            Solve(i, j);
        }
    }

    cout << answer;
    
    return 0;
}