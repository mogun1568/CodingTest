#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, blue = 0, red = 0;
    string s;
    cin >> N >> s;

    for (int i = 1; i < N; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i - 1] == 'B')
                blue++;
            else
                red++;
        }
    }
    
    if (s[N - 1] == 'B')
        blue++;
    else
        red++;

    cout << min(blue, red) + 1;
    
    return 0;
}