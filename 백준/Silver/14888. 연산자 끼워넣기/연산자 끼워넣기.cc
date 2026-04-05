#include <iostream>
#include <algorithm>
using namespace std;

int const MAX = 1e9;

int N, maxAns = -MAX, minAns = MAX; 
int A[101];
int op[4];

void DFS(int n, int cur) {
    if (n == N) {
        minAns = min(minAns, cur);
        maxAns = max(maxAns, cur);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] == 0)
            continue;

        op[i]--;

        if (i == 0) DFS(n + 1, cur + A[n]);
        else if (i == 1) DFS(n + 1, cur - A[n]);
        else if (i == 2) DFS(n + 1, cur * A[n]);
        else if (i == 3) DFS(n + 1, cur / A[n]);

        op[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];

    DFS(1, A[0]);

    cout << maxAns << "\n" << minAns;
    
    return 0;
}