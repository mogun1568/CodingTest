#include <iostream>
#include <algorithm>
using namespace std;

int memory[101];
int cost[101];
int DP[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> memory[i];

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = sum; j >= cost[i]; j--)
            DP[j] = max(DP[j], DP[j - cost[i]] + memory[i]);
    }

    for (int i = 0; i <= sum; i++) {
        if (DP[i] >= M) {
            cout << i;
            break;
        }
    }
    
    return 0;
}