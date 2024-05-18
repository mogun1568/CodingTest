#include <iostream>
#include <queue>

using namespace std;

int G;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> G;

    int i = 2, diff = 0, cnt = 0;
    bool check = false;
    
    queue<int> q;
    while (diff < G) {
        diff = i * i - (i - 1) * (i - 1);
        q.push(diff);
        cnt += diff;

        if (diff == G) {
            cout << i;
            check = true;
            break;
        }
        
        while (cnt > G) {
            cnt -= q.front();
            q.pop();
        }

        if (cnt == G) {
            cout << i << "\n";
            check = true;
        }
        
        i++;
    }

    if (!check) {
        cout << -1;
    }
    
    return 0;
}