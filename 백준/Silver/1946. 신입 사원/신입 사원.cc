#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> p[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, cnt, maxRank;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }

        sort(p, p + n);
        maxRank = p[0].second;

        cnt = 1;
        for (int i = 1; i < n; i++) {
            if (p[i].second < maxRank) {
                cnt++;
                maxRank = p[i].second;
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}