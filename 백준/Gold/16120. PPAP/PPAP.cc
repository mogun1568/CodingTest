#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int cntP = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') {
           cntP++;
           continue;
        }

        if (cntP > 1 && s[i + 1] == 'P') {
            cntP--;
            i++;
        }
        else {
            cout << "NP";
            return 0;
        }
    }

    if (cntP == 1)
        cout << "PPAP";
    else
        cout << "NP";
    
    return 0;
}