#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 5000000

int village[401][401];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++)
            village[i][j] = MAX;
    }
    
    int a, b, c;
    while (E--) {
        cin >> a >> b >> c;
        village[a][b] = c;
    }
    
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                int temp = village[i][k] + village[k][j];
                if (temp < village[i][j])
                    village[i][j] = temp;
            }
        }
    }

    int ans = MAX;
    for (int i = 1; i <= V; i++)
        ans = min(ans, village[i][i]);

    if (ans == MAX)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}