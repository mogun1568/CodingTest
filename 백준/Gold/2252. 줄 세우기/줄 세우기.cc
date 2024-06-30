#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> v[32001];
int inDegree[32001];

void Bfs() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        cout << c << " ";
        
        for (int i = 0; i < v[c].size(); i++) {
            inDegree[v[c][i]]--;

            if (inDegree[v[c][i]] == 0)
                q.push(v[c][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        v[A].push_back(B);
        inDegree[B]++;
    }

    Bfs();
    
    return 0;
}