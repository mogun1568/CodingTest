#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[20001];
int barn[20001];
bool visited[20001];

void bfs() {
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        for (auto i : v[num]) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            q.push(i);
            barn[i] = barn[num] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    int idx, value = 0, cnt;
    for (int i = 2; i <= n; i++) {
        if (barn[i] > value) {
            idx = i;
            value = barn[i];
            cnt = 1;
        } else if (barn[i] == value) {
            cnt++;
        }
    }

    cout << idx << " " << value << " " << cnt;
    
    return 0;
}