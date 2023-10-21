#include <iostream>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x, stick = 64, curlen = 0, cnt = 1; 
    cin >> x;
    
    while (stick > x) {
        stick /= 2;
    }
    curlen = stick;
    
    while (curlen < x) {
        if (curlen + stick > x) {
            stick /= 2;
            continue;
        }
        
        curlen += stick;
        cnt++;
    }
    
    cout << cnt;

    return 0;
}