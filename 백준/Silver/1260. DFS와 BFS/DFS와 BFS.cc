#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<int> vec[100001];
bool visit[1001];

vector<int> resultDfs;
vector<int> resultBfs;

void dfs(int v) {
    visit[v] = true;
    resultDfs.push_back(v);
    
    for (auto ver : vec[v]) {
        if (!visit[ver]) {  // 방문하지 않은 곳만 탐색
            dfs(ver);
        }
    }

}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = true;
    
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        resultBfs.push_back(tmp);
 
        for (auto ver : vec[tmp]) {
            if (!visit[ver]) {    // 방문하지 않은 곳만 탐색
                q.push(ver); 
                visit[ver] = true;
            }
        }
    }
}

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, v, a, b;
    cin >> n >> m >> v;
    
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);    // 양방향 간선처리
        vec[b].push_back(a);    // 양방향 간선처리
    }
    
    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end()); // 낮은 숫자부터 탐색.
    }

    dfs(v);
    memset(visit, false, sizeof(visit));
    bfs(v);
    
    for (auto d : resultDfs) {
        cout << d << " ";
    }
    cout << "\n";
    for (auto b : resultBfs) {
        cout << b << " ";
    }

    return 0;
}