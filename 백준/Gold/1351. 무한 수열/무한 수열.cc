#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> m;

long long Dfs(long long i) {
    if (m[i] == 0) {
        m[i] = Dfs(i / P) + Dfs(i / Q);
    }

    return m[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> P >> Q;

    m[0] = 1;

    cout << Dfs(N);
    
    return 0;
}