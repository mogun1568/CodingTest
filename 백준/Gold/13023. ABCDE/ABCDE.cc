#include <iostream>
#include <vector>

using namespace std;

int n;
bool result;
vector<int> rs[2001];
bool visited[2001];

void dfs(int h, int cnt) {
    if (result) {
        return;
    }

    if (cnt >= 4) {
        result = true;
        return;
    }

    for (int i = 0; i < rs[h].size(); i++) {
        if (visited[rs[h][i]]) {
            continue;
        }

        visited[rs[h][i]] = true;
        dfs(rs[h][i], cnt + 1);
        visited[rs[h][i]] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, a, b;
    cin >> n >> m;
    
    while (m--) {
        cin >> a >> b;
        rs[a].push_back(b);
        rs[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;

        if (result) {
            break;
        }
    }

    if (result) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}