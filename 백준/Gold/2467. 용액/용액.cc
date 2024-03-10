#include <iostream>
#include <cmath>

using namespace std;

int sol[100000];
int result[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, start = 0, end, mid = 2000000000, sum;
    cin >> n;
    end = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> sol[i];
    }

    while (start < end) {
        sum = sol[start] + sol[end];

        if (abs(sum) < mid) {
            result[0] = sol[start];
            result[1] = sol[end];

            if (sum == 0) {
                break;
            }

            mid = abs(sum);
        }

        if (sum < 0) {
            start++;
        } else {
            end--;
        }
    } 

    cout << result[0] << " " << result[1];

    return 0;
}