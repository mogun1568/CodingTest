#include <iostream>
#include <queue>
using namespace std;

bool prime[4000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, ans = 0, sum = 0;
    cin >> N;
   
    queue<int> q;
    for (int i = 2; i <= N; i++) {
        if (prime[i])
            continue;
        prime[i] = true;
        
        q.push(i);
        sum += i;

        while (sum > N) {
            sum -= q.front();
            q.pop();
        }

        if (sum == N)
            ans++;
        
        for (int j = i + i; j <= N; j += i)
            prime[j] = true;
    }

    cout << ans;
    
    return 0;
}