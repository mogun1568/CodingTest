#include <iostream>
#include <algorithm>

using namespace std;

long long reason[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, cnt;
    long long start = 0, end = 0, mid, tmp;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> reason[i];

        start = max(start, reason[i]);
        end += reason[i];
    }

    while (start <= end) {
        mid = (start + end) / 2;
        cnt = 0, tmp = 0;

        for (int i = 0; i < n; i++) {
            if (tmp + reason[i] > mid) {
                cnt++;
                tmp = 0;
            }

            tmp += reason[i];
        }
        if (tmp != 0) {
            cnt++;
        }

        if (cnt <= m) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
    
    return 0;
}