#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    string S, E, Q;
    cin >> S >> E >> Q;

    unordered_map<string, int> um;
    string t, name;

    while (cin >> t >> name) {
        if (t <= S) {
            um[name] = 1;
        }
        else if (t >= E && t <= Q) {
            if (um[name] == 1) {
                ans++;
                um[name]++;
            }
        }
    }

    cout << ans;
    
    return 0;
}