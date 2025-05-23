#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;

        double s = sqrt(y - x);
        int r = round(s);
        
        if (r >= s)
            cout << 2 * r - 1;
        else
            cout << 2 * r;
        cout << "\n";
    }
    
    return 0;
}