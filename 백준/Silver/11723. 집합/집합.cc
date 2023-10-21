#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, s = 0, x;
    cin >> m;
    
    string cal;
    for (int i = 0; i < m; i++) {
        cin >> cal;
        
        if (cal == "add") {
            cin >> x;
            s |= (1 << x);
        } else if (cal == "remove") {
            cin >> x;
            s &= ~(1 << x);
        } else if (cal == "check") {
            cin >> x;
            // 있는 경우는 1 이상 이므로 참
            if (s & (1 << x)) {
                cout << "1\n";
            } else {    // 없는 경우는 0뿐
                cout << "0\n";
            }
        } else if (cal == "toggle") {
            cin >> x;
            s ^= (1 << x);
        } else if (cal == "all") {
            // 비트 ex) 10000 - 1 = 1111
            s = (1 << 21) - 1;
        } else {
            s = 0;
        }
    }

    return 0;
}