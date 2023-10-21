#include <iostream>
#include <algorithm>

using namespace std;

int trees[1000000];

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, start = 0, end, result;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    sort(trees, trees + n, greater<int>());
    end = trees[0];

    while (start <= end) {
        long long tm = 0;
        int mid = (start + end) / 2;
        
        for (int i = 0; i < n; i++) {
            if (trees[i] - mid <= 0) {
                break;
            }

            tm += trees[i] - mid;
        }

        if (tm == m) {
            cout << mid;
            return 0;
        }
        
        if (tm > m) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }

    cout << result;
    
    return 0;
}