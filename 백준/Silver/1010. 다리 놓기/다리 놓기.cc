#include <iostream>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n, m, res = 1, tmp = 1;
        cin >> n >> m;
        
        // 조합 nCr을 풀어 쓴 공식
        for (int j = m; j > m - n; j--) {
            res = res * j;
            res = res / tmp++;
        }

        cout << res << '\n';
    }

    return 0;
}