#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    int start = 1, end = K;
    while (start < end) {
        int mid = (start + end) / 2, cnt = 0;

        // 구구단 1단부터 N단까지 mid보다 작거나 같은 수 카운트
        for (int i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt < K)
            start = mid + 1;
        else
            end = mid;
    }

    cout << end;
    
    return 0;
}