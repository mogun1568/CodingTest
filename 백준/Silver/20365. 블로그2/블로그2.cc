#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    int blue = 0, red = 0;
    char curC, preC;

    cin >> preC;
    N--;
    
    while (N--) {
        cin >> curC;

        if (curC != preC) {
            if (curC == 'B') {
                red++;
                preC = 'B';
            }
            else {
                blue++;
                preC = 'R';
            }
        }
    }

    if (curC == 'B')
        blue++;
    else
        red++;

    cout << min(blue, red) + 1;
    
    return 0;
}