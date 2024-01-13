#include <iostream>
#include <stack>

using namespace std;

stack<int> s[7];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, P, n, p, cnt = 0;
    cin >> N >> P;

    for (int i = 0; i < N; i++) {
        cin >> n >> p;

        while (!s[n].empty() && s[n].top() > p) {
            s[n].pop();
            cnt++;
        }

        if (s[n].empty() || s[n].top() < p) {
            s[n].push(p);
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}