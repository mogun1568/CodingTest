#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int sub[1001];
vector<int> v[1001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sub[i] = 1;
        for (int j = 0; j < v[i].size(); j++) {
            sub[i] = max(sub[i], sub[v[i][j]] + 1);
        }

        cout << sub[i] << " ";
    }
    
    return 0;
}