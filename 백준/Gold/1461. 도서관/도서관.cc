#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int books[51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        cin >> books[i];
    sort(books, books + N);

    vector<int> v;
    for (int i = 0; i < N;) {
        if (books[i] > 0)
            break;

        v.push_back(abs(books[i]));
        i += M;
    }
    for (int i = N - 1; i >= 0;) {
        if (books[i] < 0)
            break;

        v.push_back(books[i]);
        i -= M;
    }

    int ans = 0, maxDis = 0;
    for (const int& dis : v) {
        ans += 2 * dis;
        maxDis = max(maxDis, dis);
    }
    ans -= maxDis;

    cout << ans;
    
    return 0;
}