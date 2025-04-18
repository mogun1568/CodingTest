#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000;

int N, ansMax = -1000000000, ansMin = 1000000000;
int arr[11];
int operation[4];

void DFS(int idx, int ans) {
    if (idx == N - 1) {
        ansMax = max(ansMax, ans);
        ansMin = min(ansMin, ans);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operation[i] == 0)
            continue;

        operation[i]--;
        if (i == 0) DFS(idx + 1, ans + arr[idx + 1]);
        else if (i == 1) DFS(idx + 1, ans - arr[idx + 1]);
        else if (i == 2) DFS(idx + 1, ans * arr[idx + 1]);
        else DFS(idx + 1, ans / arr[idx + 1]);
        operation[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> operation[i];

    DFS(0, arr[0]);

    cout << ansMax << "\n" << ansMin;
    
    return 0;
}