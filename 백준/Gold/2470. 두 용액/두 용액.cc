#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[100000], result[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, start, mid = 2000000000, end, sum;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    start = 0;
    end = n - 1;

    while (start < end) {
        sum = arr[start] + arr[end];

        if (abs(sum) < mid) {
            result[0] = arr[start];
            result[1] = arr[end];

            if (sum == 0) {
                break;
            }

            mid = abs(sum);
        }

        if (sum > 0) {
            end--;
        } else {
            start++;
        }
    }    

    cout << result[0] << ' ' << result[1];

    return 0;
}