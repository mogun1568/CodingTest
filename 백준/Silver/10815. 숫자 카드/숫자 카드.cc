#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, mNum;
    cin >> n;
    
    int nArr[n];
    for (int i = 0; i < n; i++) {
        cin >> nArr[i];
    }
    
    cin >> m;
    
    sort(nArr, nArr + n);
    
    for (int i = 0; i < m; i++) {
        cin >> mNum;
        // binary_search() 이분 탐색 함수로 정렬이 되어 있어야 사용 가능
        if (binary_search(nArr, nArr + n, mNum)) {
            cout << '1';
        } else {
            cout << '0';
        }
        cout << ' ';
    }
    
    return 0;
}