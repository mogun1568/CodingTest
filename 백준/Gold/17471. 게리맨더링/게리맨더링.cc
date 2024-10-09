#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF 987654321

int N, answer = INF;
int pn[11];
vector<int> v[11];
bool zone[11];
bool visited[11];

int Bfs(bool type) {
    int n = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (zone[i] == type) {
            n = i;
            cnt++;
        }
    }

    memset(visited, false, sizeof(visited));
    int c = 0, people = 0;
    queue<int> q;
    visited[n] = 1;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (zone[cur] == type) {
            c++;
            people += pn[cur];
        }

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];

            if (visited[next] || zone[next] != type)
                continue;

            visited[next] = true;
            q.push(next);
        }
    }

    if (c == cnt)
        return people;

    return -1;
}

void DivideZone(int num, int cnt) {
    if (cnt > 0 && cnt < N) {
        int a = Bfs(true);
        int b = Bfs(false);
        if (a != -1 && b != -1)
            answer = min(answer, abs(a - b));  
    }

    for (int i = num + 1; i <= N; i++) {
        zone[i] = true;
        DivideZone(i, cnt + 1);
        zone[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> pn[i];

    int cnt, a;
    for (int i = 1; i <= N; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> a;
            v[i].push_back(a);
            v[a].push_back(i);
        }
    }
    
    zone[1] = true;
    DivideZone(1, 1);

    if (answer == INF) {
        cout << -1;
        return 0;
    }

    cout << answer;
    
    return 0;
}