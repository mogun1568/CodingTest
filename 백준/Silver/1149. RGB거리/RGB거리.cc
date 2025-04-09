#include <iostream>
#include <algorithm>

using namespace std;

int RGB[1001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];

        RGB[i][0] += min(RGB[i - 1][1], RGB[i - 1][2]);
        RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
        RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]);
    }

    cout << min(RGB[N][0], min(RGB[N][1], RGB[N][2]));
    
    return 0;
}