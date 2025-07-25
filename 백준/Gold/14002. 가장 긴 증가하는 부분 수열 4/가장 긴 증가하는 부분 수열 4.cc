#include <iostream>
#include <vector>
using namespace std;

int arr[1000];
vector<int> DP[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int len = 0, idx = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                if (DP[j].size() > DP[i].size())
                    DP[i] = DP[j];
            }
        }
        DP[i].push_back(arr[i]);

        if (DP[i].size() > len) {
            len = DP[i].size();
            idx = i;
        }
    }

    cout << len << "\n";
    for (auto a : DP[idx])
        cout << a << " ";
    
    return 0;
}