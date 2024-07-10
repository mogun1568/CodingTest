#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, V, E;
vector<int> grape[20001];
int visited[20001];

void Init() {
    for (int i = 1; i <= V; i++) {
        grape[i].clear();
        visited[i] = 0;
    } 
}

void Bfs(int u) {
    int group = 1;
    queue<int> q;
    visited[u] = group;
    q.push(u);

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (visited[c] == 1)
            group = 2;
        else
            group = 1;

        for (int i = 0; i < grape[c].size(); i++) {
            if (visited[grape[c][i]] != 0)
                continue;

            visited[grape[c][i]] = group;
            q.push(grape[c][i]);
        }
    }
}

bool Check() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < grape[i].size(); j++) {
            if (visited[i] == visited[grape[i][j]])
                return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K;

    while (K--) {
        cin >> V >> E;

        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            grape[u].push_back(v);
            grape[v].push_back(u);
        }

        for (int i = 1; i < V; i++) {
            if (visited[i] != 0)
                continue;

            Bfs(i);
        }

        if (Check())
            cout << "YES\n";
        else
            cout << "NO\n";
        
        Init();
    }
    
    return 0;
}