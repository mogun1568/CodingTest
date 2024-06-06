#include <iostream>
#include <algorithm>

using namespace std;

int K = 1, N;

int grape[100001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        
        cout << K << ". ";

        cin >> grape[1][0];
        grape[1][0] = 1000;
        cin >> grape[1][1];
        cin >> grape[1][2];
        grape[1][2] += grape[1][1];
        
        for (int i = 2; i <= N; i++) {
            cin >> grape[i][0];
            grape[i][0] += min(grape[i - 1][0], grape[i - 1][1]);

            cin >> grape[i][1];
            grape[i][1] += min(grape[i - 1][0], min(grape[i - 1][1], min(grape[i - 1][2], grape[i][0])));

            cin >> grape[i][2];
            grape[i][2] += min(grape[i - 1][1], min(grape[i - 1][2], grape[i][1]));
        }

        cout << grape[N][1] << "\n";
        K++;
    }
    
    return 0;
}