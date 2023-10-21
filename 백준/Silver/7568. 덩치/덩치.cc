#include <iostream>
#include <utility>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    pair<int, int> build[n];
    for (int i = 0; i < n; i++) {
        cin >> build[i].first >> build[i].second;
    }
    
    for (int i = 0; i < n; i++) {
        int rank = 1;
        for (int j = 0; j < n; j++) {
            if (build[i].first < build[j].first && build[i].second < build[j].second) {
                rank++;
            }
        }
        cout << rank << " ";
    }
    
    return 0;
}
