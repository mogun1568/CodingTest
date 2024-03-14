#include <iostream>
#include <algorithm>

using namespace std;

int block[500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, sum = 0;
    cin >> h >> w;

    for (int i = 0; i < w; i++) {
        cin >> block[i];
    }
    
    for (int i = 1; i < w - 1; i++) {
        int l = 0;
        int r = 0;

        for (int j = 0; j < i; j++) {
            l = max(l, block[j]);
        }
        for (int j = i + 1; j < w; j++) {
            r = max(r, block[j]);
        }

        int b = min(l, r);
        if (b - block[i] > 0) {
            sum += b - block[i];
        }       
    }

    cout << sum;

    return 0;
}