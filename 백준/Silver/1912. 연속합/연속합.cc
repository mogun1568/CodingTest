#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, result = -1000;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        if (i > 0) {
            arr[i] = max(arr[i], arr[i - 1] + arr[i]);
        }
        
        result = max(result, arr[i]);
    }
    
    cout << result;

    return 0;
}