#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> singer[1001];
int inDegree[1001];

void Bfs() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> v;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        v.push_back(cur);

        for (int i = 0; i < singer[cur].size(); i++) {
            int next = singer[cur][i];
            inDegree[next]--;

            if (inDegree[next] == 0)
                q.push(next);
        }
    }

    if (v.size() != N) {
        cout << 0;
        return;
    }

    for (auto i : v)
        cout << i << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a;
        
        vector<int> v;
        for (int j = 0; j < a; j++) {
            cin >> b;
            v.push_back(b);
        }

        for (int j = 0; j < a - 1; j++) {
            for (int k = j + 1; k < a; k++) {
                singer[v[j]].push_back(v[k]);
                inDegree[v[k]]++;
            }
        }
    }

    Bfs();
    
    return 0;
}