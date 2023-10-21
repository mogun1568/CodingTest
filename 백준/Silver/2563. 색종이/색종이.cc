#include <iostream>

using namespace std;

bool paper[100][100];

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, y, cnt = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                if (!paper[j][k]) {
                    paper[j][k] = true;
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt;

    return 0;
}