#include <iostream>
#include <cmath>

using namespace std;

int K, sum, answer;
int arr[13];
bool visited[14][2600001];

void Dfs(int idx, int n) {
    if (idx > K)
        return;

    if (visited[idx][n])
        return;
    visited[idx][n] = true;

    Dfs(idx + 1, n);
    Dfs(idx + 1, abs(n - arr[idx]));
    Dfs(idx + 1, n + arr[idx]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    Dfs(0, 0);

    for (int i = 1; i <= sum; i++) {
        if (!visited[K][i])
            answer++;
    }

    cout << answer;
    
    return 0;
}