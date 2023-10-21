#include <iostream>
#include <algorithm>

using namespace std;

unsigned int lans[10000];

int main() {
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned int k, n, start = 1, end = 0, mid, result = 1, cnt;
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> lans[i];
        end = max(end, lans[i]);
    }

    while (start <= end) {
        cnt = 0;
        mid = (start + end) / 2;
        
        for (auto lan : lans) {
            cnt += lan / mid;    
        }
        
        if (cnt >= n) {
            result = max(result, mid);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << result;
    
    return 0;
}