#include <iostream>
#include <queue>

using namespace std;

int N, sum, answer;
bool prime[4000001];
queue<int> q;

void Solve() {
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
            answer++;
        
        for (int j = i + i; j <= N; j += i) {
            prime[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    Solve();

    cout << answer;
    
    return 0;
}