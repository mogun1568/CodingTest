#include <iostream>
#include <cmath>
using namespace std;

int N, ans;
int col[15];

void DFS(int r) {
    if (r == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[r] = i;
        bool check = false;
        
        for (int j = 0; j < r; j++) {
            if(col[r] == col[j] || abs(col[r] - col[j]) == r - j){
                // 1. 같은 행에 있는가
                // 2. 대각선에 있는가
                check = true;
                break;
            }
        }

        if (!check)
            DFS(r + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    DFS(0);

    cout << ans;
    
    return 0;
}