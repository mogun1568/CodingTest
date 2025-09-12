#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2000

int area[101];
int fw[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        cin >> area[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                fw[i][j] = MAX;
        }
    }
    
    int a, b, l;
    while (r--) {
        cin >> a >> b >> l;
        fw[a][b] = l;
        fw[b][a] = l;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = fw[i][k] + fw[k][j];
                if (temp < fw[i][j])
                    fw[i][j] = temp;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (fw[i][j] <= m)
                sum += area[j];
        }

        ans = max(ans, sum);
    }

    cout << ans;
    
    return 0;
}