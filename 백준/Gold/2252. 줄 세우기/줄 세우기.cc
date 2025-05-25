#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v[32001];
int inDegree[32001];

void BFS() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int A = q.front();
        q.pop();

        cout << A << " ";

        for (int i = 0; i < v[A].size(); i++) {
            inDegree[v[A][i]]--;
            if (inDegree[v[A][i]] == 0)
                q.push(v[A][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, A, B;
    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        v[A].push_back(B);
        inDegree[B]++;
    }

    BFS();
    
    return 0;
}