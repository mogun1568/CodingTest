#include <iostream>
#include <algorithm>

using namespace std;

int maxDp[3];
int minDp[3];
int temp[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c, tmp1, tmp2, tmp3;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        copy(begin(maxDp), end(maxDp), begin(temp));
        maxDp[0] = a + max(temp[0], temp[1]);
        maxDp[1] = b + max(temp[0], max(temp[1], temp[2]));
        maxDp[2] = c + max(temp[1], temp[2]);

        copy(begin(minDp), end(minDp), begin(temp));
        minDp[0] = a + min(temp[0], temp[1]);
        minDp[1] = b + min(temp[0], min(temp[1], temp[2]));
        minDp[2] = c + min(temp[1], temp[2]);
    }

    cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << ' ' << min(minDp[0], min(minDp[1], minDp[2]));

    return 0;
}