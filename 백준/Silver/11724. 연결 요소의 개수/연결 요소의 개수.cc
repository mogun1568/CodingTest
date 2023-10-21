#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[1001];
bool visit[1001];

void bfs(int start) {
    queue<int> q;
    visit[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto c : vec[cur]) {
            if (!visit[c]) {
                visit[c] = true;
                q.push(c);
            }
        }
    }
}

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, u, v, cnt = 0;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            bfs(i);
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}