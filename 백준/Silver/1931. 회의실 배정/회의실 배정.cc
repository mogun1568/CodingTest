#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, e, curE, cnt = 1;
    cin >> n;

    vector<pair<int, int>> room;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        room.push_back({e, s});
    }

    sort(room.begin(), room.end());

    curE = room[0].first;
    for (int i = 1; i < n; i++) {
        if (room[i].second >= curE) {
            cnt++;
            curE = room[i].first;
        }
    }

    cout << cnt;
    
    return 0;
}