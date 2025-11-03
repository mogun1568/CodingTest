#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;

        vector<string> v;
        int cnt = 0;
        
        do {
            v.push_back(str);
            cnt++;
            
            if (cnt >= 2)
                break;
        } while(next_permutation(str.begin(), str.end()));

        cout << v.back() << "\n";
    }
    
    return 0;
}