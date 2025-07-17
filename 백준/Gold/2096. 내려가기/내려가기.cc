#include <iostream>
#include <algorithm>
using namespace std;

int maxDP[3], minDP[3], temp[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b, c;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;

        copy(begin(maxDP), end(maxDP), begin(temp));
        maxDP[0] = a + max(temp[0], temp[1]);
        maxDP[1] = b + max(temp[0], max(temp[1], temp[2]));
        maxDP[2] = c + max(temp[1], temp[2]);

        copy(begin(minDP), end(minDP), begin(temp));
        minDP[0] = a + min(temp[0], temp[1]);
        minDP[1] = b + min(temp[0], min(temp[1], temp[2]));
        minDP[2] = c + min(temp[1], temp[2]);
    }

    cout << max(maxDP[0], max(maxDP[1], maxDP[2])) << ' ' << min(minDP[0], min(minDP[1], minDP[2]));

    return 0;
}