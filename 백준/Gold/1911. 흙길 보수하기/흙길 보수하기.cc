#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, L;
vector<pair<int, int>> puddle;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L;

    int s, e;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        puddle.push_back({s, e});
    }
    sort(puddle.begin(), puddle.end());
    
    int answer = 0, idx = 0;
    for (int i = 0; i < N; i++) {
        idx = max(idx, puddle[i].first + 1);

        int cnt = ceil((puddle[i].second - idx + 1) / (double)L);
        answer += cnt;
        idx += L * cnt;
    }

    cout << answer;
    
    return 0;
}