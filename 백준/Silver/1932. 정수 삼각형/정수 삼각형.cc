#include <iostream>
#include <algorithm>

using namespace std;

int triangle[500][500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, ans = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];

            if (i > 0) {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == i)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }

            if (i == N - 1)
                ans = max(ans, triangle[i][j]);
        }
    }

    cout << ans;
    
    return 0;
}