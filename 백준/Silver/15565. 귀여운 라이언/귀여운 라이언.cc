#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1000000

int N, K, answer = MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    int doll;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        cin >> doll;

        if (doll == 1) {
            q.push(i);
        }

        if (q.size() == K) {
            answer = min(answer, q.back() - q.front() + 1);
            q.pop();
        }
    }

    if (answer == MAX) {
        cout << -1;
    }
    else {
        cout << answer;
    }
    
    return 0;
}