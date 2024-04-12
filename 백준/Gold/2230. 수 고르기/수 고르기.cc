#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, start = 0, end = 0, answer = 2000000001;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    while (start < n && end < n) {
        int result = arr[end] - arr[start];
        
        if (result < m) {
          end++;
        } else {
          answer = min(answer, result);
          start++;
        }
    }
    
    cout << answer;
    
    return 0;
}