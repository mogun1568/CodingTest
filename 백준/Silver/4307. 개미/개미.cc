#include <iostream>
#include <algorithm>

using namespace std;

int T, L, N, ant;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> L >> N;

        int minTime = 0, maxTime = 0;
        for (int i = 0; i < N; i++) {
            cin >> ant;

            int antMin = min(ant, L - ant);
            int antMax = max(ant, L - ant);

            minTime = max(minTime, antMin);
            maxTime = max(maxTime, antMax);
        }
    
        cout << minTime << " " << maxTime << "\n";
    }
    
    return 0;
}