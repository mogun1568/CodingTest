#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, t;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        if (v[i].first >= pq.top()) {
            pq.pop();
        }
        pq.push(v[i].second);
    }

    cout << pq.size();

    return 0;
}