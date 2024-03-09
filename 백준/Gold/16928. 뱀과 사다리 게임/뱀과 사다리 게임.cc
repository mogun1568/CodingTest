#include <iostream>
#include <queue>

using namespace std;

int board[101];
int cnt[101];

void bfs() {
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int b = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nb = b + i;

            if (nb == 100) {
                cnt[nb] = cnt[b] + 1;
                return;
            } else if (nb < 100) {
                while (board[nb] != 0) {
                    nb = board[nb];
                }

                if (cnt[nb] != 0) {
                    continue;
                }
                
                cnt[nb] = cnt[b] + 1;
                q.push(nb);
            }
        } 
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m;
    
    for (int i = 0; i < n + m; i++) {
        cin >> x >> y;
        board[x] = y;
    }
    
    bfs();

    cout << cnt[100];

    return 0;
}