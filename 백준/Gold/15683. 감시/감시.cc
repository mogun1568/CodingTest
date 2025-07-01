#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 70;
int office[9][9];
vector<pair<int, int>> v;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int Solve() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (office[i][j] == 0)
                cnt++;
        }
    }

    return cnt;
}

void Block(int r, int c, int d) {
    d %= 4;

    while (1) {
        r += dr[d];
        c += dc[d];

        if (r < 1 || r > N || c < 1 || c > M)
            break;

        if (office[r][c] == 6)
            break;

        if (office[r][c] == 0)
            office[r][c] = 7;
    }
}

void DFS(int idx) {
    if (idx == v.size()) {
        ans = min(ans, Solve());
        return;
    }
    
    int temp[9][9];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            temp[i][j] = office[i][j];
    }
    
    int r = v[idx].first;
    int c = v[idx].second;
    int num = office[r][c];

    for (int k = 0; k < 4; k++) {
        if ((num == 2 && k > 1) || (num == 5 && k > 0))
            break;
        
        switch (num) {
            case 1:
                Block(r, c, k);
                break;
            case 2:
                Block(r, c, k);
                Block(r, c, k + 2);
                break;
            case 3:
                Block(r, c, k);
                Block(r, c, k + 1);
                break;
            case 4:
                Block(r, c, k);
                Block(r, c, k + 1);
                Block(r, c, k + 2);
                break;
            case 5:
                Block(r, c, k);
                Block(r, c, k + 1);
                Block(r, c, k + 2);
                Block(r, c, k + 3);
                break;
        }
        
        DFS(idx + 1);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
                office[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> office[i][j];

            if (office[i][j] > 0 && office[i][j] < 6)
                v.push_back({i, j});
        }
    }

    DFS(0);

    cout << ans;
    
    return 0;
}