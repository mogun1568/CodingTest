#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int S, E, Q, h, m, ans = 0;
    string strS, strE, strQ;
    
    scanf("%d:%d", &h, &m);
    S = h * 60 + m;
    scanf("%d:%d", &h, &m);
    E = h * 60 + m;
    scanf("%d:%d", &h, &m);
    Q = h * 60 + m;

    unordered_map<string, int> um;

    char temp[21];
    while (scanf("%d:%d %s", &h, &m, temp) == 3) {
        int t = h * 60 + m;
        string name(temp);

        if (t <= S) {
            if (um.count(name) == 0)
                um[name]++;
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