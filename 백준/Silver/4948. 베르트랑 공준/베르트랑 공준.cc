#include <iostream>

using namespace std;

const int Max = 123456 * 2 + 1;

int prime[Max];

int main() {
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= Max; i++) {
        if (!prime[i]) {
            for (int j = i + i; j <= Max; j += i) {
                prime[j] = true;
            }
        }
    }

    int n;
    while (1) {
        cin >> n;

        if (n == 0) {
            break;
        }
        
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (!prime[i]) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}