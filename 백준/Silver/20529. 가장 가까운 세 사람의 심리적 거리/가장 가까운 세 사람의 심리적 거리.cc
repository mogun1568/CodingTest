#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> mbti;

int check(vector<string> v) {
    int cnt = 0;
    
    for (int i = 0; i < 4; i++) {
        if (v[0][i] != v[1][i]) {
            cnt++;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (v[0][i] != v[2][i]) {
            cnt++;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (v[1][i] != v[2][i]) {
            cnt++;
        }
    }
    
    return cnt;
}

int cbn() {
    int result = 100;
    
    vector<int> s, temp;
    for (int i = 0; i < mbti.size(); i++) {
        s.push_back(i);

        if (i < 3) {
            temp.push_back(1);
        } else {
            temp.push_back(0);
        }
    }

    vector<string> v;
    do {
        for (int i = 0; i < s.size(); i++) {
            if (temp[i] == 1) {
                v.push_back(mbti[s[i]]);
            }
        }
        
        result = min(result, check(v));
        v.clear();
    } while (prev_permutation(temp.begin(), temp.end()));

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            mbti.push_back(str);
        }

        if (n < 33) {
            cout << cbn() << "\n";
        } else {
            cout << 0 << "\n";
        }
        
        mbti.clear();
    }

    return 0;
}