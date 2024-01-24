#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt = 0;
    cin >> n;

    map<int, string> in;
    map<string, int> out;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        in[i] = s;
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        out[s] = i;
    }

    cnt += out[in[0]] - 0;
    
    int idx = out[in[0]];
    for (int i = 1; i < n; i++) {
        if (out[in[i]] > idx) {
            if (out[in[i]] - idx > 1) {
                cnt += out[in[i]] - idx - 1;
            }
            
            idx = out[in[i]];
        }
    }

    cout << cnt;
    
    return 0;
}