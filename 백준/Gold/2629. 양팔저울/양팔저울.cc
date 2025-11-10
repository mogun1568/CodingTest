#include <iostream>
#include <cmath>
using namespace std;

int n;
int weight[31];
bool DP[31][15001];

void DFS(int idx, int w) {
    if (idx > n || DP[idx][w])
        return;

    DP[idx][w] = true;

    DFS(idx + 1, w + weight[idx]);
    DFS(idx + 1, abs(w - weight[idx]));
    DFS(idx + 1, w);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    DFS(0, 0);

    int m, w;
    cin >> m;
    while (m--) {
        cin >> w;

        if (w > 15000)
            cout << "N ";
        else {
            if (DP[n][w])
                cout << "Y ";
            else
                cout << "N ";
        }
    }
    
    return 0;
}