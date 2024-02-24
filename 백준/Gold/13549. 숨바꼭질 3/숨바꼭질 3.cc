#include <iostream>
#include <queue>

using namespace std;

int k;
int area[100001];
bool visited[100001];

void bfs(int d) {
    queue<int> q;
    q.push(d);

    while (!q.empty()) {
        int cd = q.front();
        q.pop();

        if (cd == k) {
            return;
        }

        int nd = 2 * cd;
        if (nd <= 100000 && !visited[nd]) {
            visited[nd] = true;
            area[nd] = area[cd];
            q.push(nd);
        }

        nd = cd - 1;
        if (nd >= 0 && !visited[nd]) {
            visited[nd] = true;
            area[nd] = area[cd] + 1;
            q.push(nd);
        }

        nd = cd + 1;
        if (nd <= 100000 && !visited[nd]) {
            visited[nd] = true;
            area[nd] = area[cd] + 1;
            q.push(nd);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> k;

    bfs(n);

    cout << area[k];

    return 0;
}