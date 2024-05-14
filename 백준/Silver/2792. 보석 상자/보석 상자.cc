#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int box[300000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> box[i];
    }

    int start = 1, end = *max_element(box, box + M), mid;

    while (start <= end) {
        mid = (start + end) / 2;

        int cnt = 0;

        for (int i = 0; i < M; i++) {
            cnt += box[i] / mid;
            if (box[i] % mid != 0) {
                cnt++;
            }
        }

        if (cnt > N) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << start;

    return 0;
}