#include <iostream>
using namespace std;

int N, r, c, ans;

void DFS(int y, int x, int size) {
    if (y == r && x == c)  {
        cout << ans;
        return;
    }

    // r, c가 현재 사분면에 존재한다면
    if (r >= y && r < y + size && c >= x && c < x + size) {
        DFS(y, x, size / 2);
        DFS(y, x + size / 2, size / 2);
        DFS(y + size / 2, x, size / 2);
        DFS(y + size / 2, x + size / 2, size / 2);
    }
    else
        ans += size * size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> r >> c;
    
    DFS(0, 0, (1 << N));
    
    return 0;
}