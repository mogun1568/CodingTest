#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100000000

int N, S, answer = MAX;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;

    int a, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;

        sum += a;
        q.push(a);
        
        while (sum >= S) {
            int len = q.size();
            answer = min(answer, len);

            sum -= q.front();
            q.pop();
        }
    }

    if (answer == MAX)
        cout << 0;
    else
        cout << answer;
    
    return 0;
}