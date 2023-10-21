#include <iostream>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int e, s, m;
    cin >> e >> s >> m;

    while (1) {
         if ((s - e) % 15 == 0 && (s - m) % 19 == 0) {
            cout << s;
            return 0;
         }

         s += 28;
    }
}