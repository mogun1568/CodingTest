#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];

        house[i][0] += min(house[i - 1][1], house[i - 1][2]);
        house[i][1] += min(house[i - 1][0], house[i - 1][2]);
        house[i][2] += min(house[i - 1][0], house[i - 1][1]);
    }

    cout << min(house[N][0], min(house[N][1], house[N][2]));
    
    return 0;
}