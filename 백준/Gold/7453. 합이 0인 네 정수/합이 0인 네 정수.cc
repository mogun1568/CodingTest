#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[4000][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }

    vector<int> sumAB, sumCD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumAB.push_back(arr[i][0] + arr[j][1]);
            sumCD.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());

    long long ans = 0;
    for (int i = 0; i < sumAB.size();) {
        long long countAB = 0;
        int num = sumAB[i];
     
        while (i < sumAB.size() && sumAB[i] == num) {
          countAB++;
          i++;
        }
     
        int lower = lower_bound(sumCD.begin(), sumCD.end(), -num) - sumCD.begin();
        int upper = upper_bound(sumCD.begin(), sumCD.end(), -num) - sumCD.begin();
     
        ans += countAB * (upper - lower);
    }

    cout << ans;
    
    return 0;
}