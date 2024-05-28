#include <iostream>
#include <cmath>

using namespace std;

long long N, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    long long i = -1, a, b, num = 0, temp = 0;
    while (K - temp * (i + 1) > 0) {
        K -= temp * (i + 1);     
        num += temp;
        i++;

        temp =  9 * pow(10, i);
    } 

    a = K / (i + 1);
    b = K % (i + 1);
    
    num += a;
    if (b != 0) {
        num++;
    }
    else {
        b = i + 1;
    }

    if (num > N) {
        cout << -1;
        return 0;
    }

    cout << to_string(num)[b - 1];
    
    return 0;
}