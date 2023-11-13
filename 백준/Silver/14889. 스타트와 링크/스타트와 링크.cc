#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int s[20][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> idx, temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }

        idx.push_back(i);
        if (i < n / 2) {
            temp.push_back(1);
        } else {
            temp.push_back(0);
        }
    }

    int minDiff = 2000;
    do {
        vector<int> si, li;
        int ts = 0, tl = 0;
        
        for (int i = 0; i < n; ++i) {
            if (temp[i] == 1) {
                si.push_back(idx[i]);
            } else {
                li.push_back(idx[i]);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                ts += s[si[i]][si[j]];
                tl += s[li[i]][li[j]];
            }
        }

        minDiff = min(minDiff, abs(ts - tl));
    
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << minDiff;
    
    return 0;
}