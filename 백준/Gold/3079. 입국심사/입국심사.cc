#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long arr[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long start = 1, end = *max_element(arr, arr + N) * M, mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        
        long long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += mid / arr[i];

            if (cnt > M) {
                break;
            }
        }

        if (cnt >= M) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
    
    return 0;
}