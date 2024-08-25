#include <iostream>

using namespace std;

int N, M;
long long answer;
long long sumMod[1000001];
long long mod[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> sumMod[i];
        sumMod[i] += sumMod[i - 1];
        sumMod[i] %= M;
    }

    for (int i = 1; i < M; i++)
        mod[i] = -1;

    for (int i = 1; i <= N; i++) {
        answer += ++mod[sumMod[i]];
    }

    cout << answer;
    
    return 0;
}