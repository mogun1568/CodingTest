#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, b;
    cin >> n;

    long long cnt = 0;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        cin >> b;

        while (!s.empty() && s.top() <= b) {
            s.pop();
        }
        s.push(b);

        cnt += s.size() - 1;
    }

    cout << cnt;
    
    return 0;
}