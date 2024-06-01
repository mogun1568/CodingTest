#include <iostream>
#include <algorithm>

using namespace std;

long long N, L, R, X, answer;
long long q[15];

void Dfs(int idx, int cnt, long long sum, int easy) {
    if (cnt > 1) {
        if (sum >= L && sum <= R) {
            if (q[idx] - easy >= X) {
                answer++;
            }
        }
    }

    for (int i = idx + 1; i < N; i++) {
        Dfs(i, cnt + 1, sum + q[i], easy);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) {
        cin >> q[i];
    }
    sort(q, q + N);

    for (int i = 0; i < N; i++) {
        Dfs(i, 1, q[i], q[i]);
    }

    cout << answer;
    
    return 0;
}