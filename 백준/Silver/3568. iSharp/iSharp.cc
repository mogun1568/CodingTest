#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;

    while (true) {
        string str;
        cin >> str;
        
        if (str.back() == ',') {
            str.pop_back();
            v.push_back(str);
        }
        else if (str.back() == ';') {
            str.pop_back();
            v.push_back(str);
            break;
        }
        else
            v.push_back(str);
    }

    for (int i = 1; i < v.size(); i++) {
        cout << v[0];
        
        int j;
        for (j = v[i].length() - 1; j >= 0 ; j--) {
            if (isalpha(v[i][j]))
                break;
            else {
                if (v[i][j] == '[')
                    cout << ']';
                else if (v[i][j] == ']')
                    cout << '[';
                else
                    cout << v[i][j];
            }
        }

        cout << ' ' << v[i].substr(0, j + 1) << ";\n";
    }
    
    return 0;
}