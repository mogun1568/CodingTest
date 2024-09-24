#include <iostream>

using namespace std;

long long N;
// 주기는 M = 10^k (k>2)일때, 항상 15 * 10^(k-1)이다.
int arr[1500000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    N %= 1500000;
    
    arr[1] = 1;
    for (long long i = 2; i <= N; i++)
        arr[i] = (arr[i - 2] + arr[i - 1]) % 1000000;

    cout << arr[N] << "\n";
    
    return 0;
}