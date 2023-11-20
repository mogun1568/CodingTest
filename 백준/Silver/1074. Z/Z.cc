#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, result;

void dfs(int addR, int addC) {
    if (n < 2) {
        return;
    }

    int order = n * n / 4;
    n /= 2;

    if (r < addR + n && c < addC + n) {
        dfs(addR, addC);
    } else if (r < addR + n && c >= addC + n) {
        result += order;
        dfs(addR, addC + n);
    } else if (r >= addR + n && c < addC + n) {
        result += order * 2;
        dfs(addR + n, addC);
    } else if (r >= addR + n && c >= addC + n) {
        result += order * 3;
        dfs(addR + n, addC + n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    n = pow(2, n);

    dfs(0, 0);

    cout << result;

    return 0;
}