#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, cnt = 1;
    cin >> n >> k;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    cout << '<';
    while (!q.empty()) {
        if (cnt >= k) {
            cnt = 1;
            
            cout << q.front();
            if (q.size() != 1) {
                cout << ", ";
            }
        } else {
            q.push(q.front());
            cnt++;
        }
        q.pop();
    }
    cout << '>';

    return 0;
}