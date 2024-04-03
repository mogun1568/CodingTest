#include <iostream>

using namespace std;

int bottom[500001], top[500001], result[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, h, a, b, minObs = 300000, cnt;
    cin >> n >> h;

    for (int i = 0; i < n / 2; i++) {
        cin >> a >> b;
        bottom[a]++;
        top[h - b + 1]++;
    }

    for (int i = h - 1; i >= 0; i--) {
        bottom[i] += bottom[i + 1];
    }

    for (int i = 1; i <= h; i++) {
        top[i] += top[i - 1];
        result[i] = bottom[i] + top[i];

        if (result[i] < minObs) {
            minObs = result[i];
            cnt = 1;
        } else if (result[i] == minObs) {
            cnt++;
        }
    }

    cout << minObs << " " << cnt;
    
    return 0;
}