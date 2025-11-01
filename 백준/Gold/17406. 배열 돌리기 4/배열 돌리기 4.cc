#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 5000

struct Rota {
    int r, c, s;
};

int N, M, K, ans = MAX;
int arr[51][51];
int arrC[51][51];

vector<Rota> v;
bool visited[6];
vector<int> cur;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void Copy() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            arrC[i][j] = arr[i][j];
    }
}

int Calculate() {
    int result = MAX;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= M; j++)
            sum += arrC[i][j];

        result = min(result, sum);
    }

    return result;
}

void Solve(int idx) {
    int r = v[idx].r;
    int c = v[idx].c;
    int s = v[idx].s;
    
    for (int i = 1; i <= s; i++) {
        int cr = r - i;
        int cc = c - i;
        int temp = arrC[cr][cc];
        
        for (int j = 0; j < 4; j++) {
            for (int k = 1; k <= i * 2; k++) {
                int nr = cr + dr[j];
                int nc = cc + dc[j];
                arrC[cr][cc] = arrC[nr][nc];
                cr = nr;
                cc = nc;
            }
        }

        arrC[cr][cc + 1] = temp;
    }
}

void DFS(int cnt) {
    if (cnt == K) {
        Copy();
        for (int i = 0; i < cnt; i++)
            Solve(cur[i]);

        ans = min(ans, Calculate());
        return;
    }
    
    for (int i = 0; i < K; i++) {
        if (visited[i])
            continue;

        visited[i] = true;
        cur.push_back(i);
        DFS(cnt + 1); 
        visited[i] = false;
        cur.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];
    }

    int r, c, s;
    for (int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        v.push_back({r, c, s});
    }

    DFS(0);

    cout << ans;
    
    return 0;
}