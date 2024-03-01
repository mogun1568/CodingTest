#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[100000], result[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, start, mid, end, mv;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    start = 0;
    end = n - 1;
    result[0] = arr[start];
    result[1] = arr[end];
    mv = abs(arr[start] + arr[end]);

    while (start < end) {
        mid = arr[start] + arr[end];

        if (mid == 0) {
            result[0] = arr[start];
            result[1] = arr[end];
            break;
        }

        if (abs(mid) < mv) {
            mv = abs(mid);
            result[0] = arr[start];
            result[1] = arr[end];
        }

        if (mid > 0) {
            end--;
        } else {
            start++;
        }
    }    

    cout << result[0] << ' ' << result[1];

    return 0;
}