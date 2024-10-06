#include <iostream>

using namespace std;

#define MOD 1000000007

long long power(long long n, long long k) {
    long long ret = 1;
    while(k) {
        if (k % 2)
            ret = (ret * n) % MOD;
        
        n = (n * n) % MOD;
        k /= 2;
    }
    
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    long long A = 1, B = 1;
    for (int i = n; i >= n - k + 1; --i)
        A = (A * i) % MOD;
    for (int i = 2; i <= k; ++i)
        B = (B * i) % MOD;
    
    cout << (A * power(B, MOD - 2)) % MOD;
    
    return 0;
}