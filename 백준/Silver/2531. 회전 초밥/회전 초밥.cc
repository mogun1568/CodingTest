#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int sushi[3001];
int belt[33000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, d, k, c, num, cnt = 0, result = 0;
    cin >> n >> d >> k >> c;

    queue<int> q;
    for (int i = 1; i <= n + k; i++) {
        if (i <= n) {
            cin >> num;
            belt[i] = num;
        } else {
            num = belt[i - n];
        }

        if (i > k) {
            sushi[q.front()]--;
            if (sushi[q.front()] == 0) {
                cnt--;
            }
            q.pop();
        }
    
        if (sushi[num] == 0) {
            cnt++;
        }
        sushi[num]++;
        q.push(num);
        
        if (sushi[c] == 0) {
            result = max(result, cnt + 1);
        } else {
            result = max(result, cnt);
        }
    }

    cout << result;    
    
    return 0;
}