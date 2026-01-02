#include <iostream>
#include <unordered_map>
using namespace std;

int N, S;
int arr[40];
unordered_map<int, int> um;
long long ans;

void left(int n, int sum) {
    if (n == N / 2) {
        um[sum]++;
        return;
    }

    left(n + 1, sum);
    left(n + 1, sum + arr[n]);
}

void right(int n, int sum) {
    if (n == N) {
        ans += um[S - sum];
        return;
    }

    right(n + 1, sum);
    right(n + 1, sum + arr[n]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    left(0, 0);
    right(N / 2, 0);

    if (S == 0)
        ans--;

    cout << ans;
    
    return 0;
}