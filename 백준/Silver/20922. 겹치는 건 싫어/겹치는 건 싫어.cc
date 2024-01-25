#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, a, result = 0;
    cin >> n >> k;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a;

        arr[a]++;
        q.push(a);
        
        if (arr[a] > k) {
            result = max(result, static_cast<int>(q.size()) - 1);
            
            while (q.front() != a) {
                arr[q.front()]--;
                q.pop();
            }
            arr[q.front()]--;
            q.pop();
        }
    }
    result = max(result, static_cast<int>(q.size()));

    cout << result;
    
    return 0;
}