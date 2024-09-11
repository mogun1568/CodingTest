#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m, answer;
int arr[1001][1001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - '0';
            arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int k = 1, cnt = 0;
            while (k <= i) {
                cnt = arr[i][j] - arr[i - k][j] - arr[i][j - k] + arr[i - k][j - k];
                if (cnt == k * k)
                    answer = max(answer, cnt);
                else
                    break;
                
                k++;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}