#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

bool alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string s, ans = "";
        getline(cin, s);

        vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i - 1] == ' ')
                v.push_back(i);
        }
        
        int idx = -1;
        for (auto i : v) {
            char c = toupper(s[i]);
            if (!alpha[c - 'A']) {
                alpha[c - 'A'] = true;
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            for (int i = 0; i < s.length(); i++) {
                if (i == idx) 
                    cout << '[' << s[i] << ']';
                else
                    cout << s[i];  
            }
            cout << "\n";
            continue;
        }

        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i - 1] == ' ' || s[i] == ' ') {
                cout << s[i];
                continue;
            }

            if (flag) {
                cout << s[i];
                continue;
            }

            char c = toupper(s[i]);
            if (!alpha[c - 'A']) {
                alpha[c - 'A'] = true;
                flag = true;
                cout << '[' << s[i] << ']';
            }
            else
                cout << s[i];
        }
        
        cout << "\n";
    }
    
    return 0;
}