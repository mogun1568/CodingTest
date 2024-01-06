#include <iostream>
#include <algorithm>

using namespace std;

int tree[10000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, maxdiff;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> tree[i];
        }
        sort(tree, tree + n, greater<>());

        maxdiff = 0;
        maxdiff = max(maxdiff, tree[0] - tree[1]);
        maxdiff = max(maxdiff, tree[n - 2] - tree[n - 1]);
        for (int i = 0; i < n - 2; i ++) {
            maxdiff = max(maxdiff, tree[i] - tree[i + 2]);
        }

        cout << maxdiff << "\n";
    }
    
    return 0;
}