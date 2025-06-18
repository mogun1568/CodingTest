#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, cnt, maxRank;
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> p[i].first >> p[i].second;
        sort(p, p + N);
        
        cnt = 1;
        maxRank = p[0].second;
        for (int i = 1; i < N; i++) {
            if (p[i].second < maxRank) {
                cnt++;
                maxRank = p[i].second;
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}