#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
int visit[1000001];

void bfs() {
    queue<int> q;
    visit[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        if (s == g) {
            cout << visit[s] - 1;
            return;
        }

        if (s + u <= f && visit[s + u] == 0) {
            visit[s + u] = visit[s] + 1;
            q.push(s + u);
        }
        if (s - d > 0 && visit[s - d] == 0) {
            visit[s - d] = visit[s] + 1;
            q.push(s - d);
        }
    }

    cout << "use the stairs";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    bfs();

    return 0;
}