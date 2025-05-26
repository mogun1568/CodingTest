#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, S; 
    cin >> N >> S;

    int start = 0, sum = 0, ans = MAX;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        sum += arr[i];

        while (sum >= S) {
            ans = min(ans, i - start + 1);
            sum -= arr[start++];
        }
    }

    if (ans == MAX)
        cout << 0; 
    else
        cout << ans;
    
    return 0;
}