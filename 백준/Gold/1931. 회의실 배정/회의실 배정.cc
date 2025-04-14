#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> meet[100000];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, s, e;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        meet[i].first = s;
        meet[i].second = e;
    }

    sort(meet, meet + N, cmp);

    int ans = 1, curE = meet[0].second;
    for (int i = 1; i < N; i++) {
        if (meet[i].first >= curE) {
            ans++;
            curE = meet[i].second;
        }
    }

    cout << ans;
    
    return 0;
}