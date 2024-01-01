#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, a, b, c, result = 1;
    cin >> n >> m >> k;

    int dir[3][2] = {0, 0, k / m, k % m - 1, n - 1, m - 1};
    if (k == 0) {
        dir[1][0] = 0;
        dir[1][1] = 0;
    }

    for (int i = 0; i < 2; i++) {
        a = max(dir[i + 1][0] - dir[i][0], dir[i + 1][1] - dir[i][1]);
        b = min(dir[i + 1][0] - dir[i][0], dir[i + 1][1] - dir[i][1]);
        c = a + b;
        
        for (int j = a + 1; j <= c; j++) {
            result *= j;
        }
        for (int j = 2; j <= b; j++) {
            result /= j;
        }
    }
    

    cout << result;
    
    return 0;
}