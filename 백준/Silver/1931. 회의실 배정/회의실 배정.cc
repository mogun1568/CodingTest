#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, e, curE, cnt = 1;
    cin >> n;

    vector<pair<int, int>> room;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        room.push_back({s, e});
    }

    sort(room.begin(), room.end(), cmp);

    curE = room[0].second;
    for (int i = 1; i < n; i++) {
        if (room[i].first >= curE) {
            cnt++;
            curE = room[i].second;
        }
    }

    cout << cnt;
    
    return 0;
}