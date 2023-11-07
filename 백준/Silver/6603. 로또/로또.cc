#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        int k, e;
        cin >> k;

        if (k == 0) {
            return 0;
        }

        vector<int> s, temp;
        for (int i = 0; i < k; i++) {
            cin >> e;
            s.push_back(e);

            if (i < 6) {
                temp.push_back(1);
            } else {
                temp.push_back(0);
            }
        }

        do {
            for (int i = 0; i < k; i++) {
                if (temp[i]) {
                    cout << s[i] << " ";
                }
            }
            cout << "\n";
        } while(prev_permutation(temp.begin(), temp.end()));
        cout << "\n";
    }
    
    return 0;
}