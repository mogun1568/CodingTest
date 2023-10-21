#include <iostream>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long s, n = 0, sum;
    cin >> s;
    
    while (sum <= s) {
        n++;
        
        if (n % 2 == 0) {
            sum = (n + 1) * (n / 2);
        } else {
            sum = (n + 1) * (n / 2) + ((n / 2) + 1);
        }
    }
    
    cout << n - 1;

    return 0;
}