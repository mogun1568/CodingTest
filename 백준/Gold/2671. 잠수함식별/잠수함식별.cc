#include <iostream>
#include <string>

using namespace std;

string S;
bool check;

void Solve(int idx) {
    if (idx >= S.length()) {
        check = true;
        return;
    }
    
    if (check) {
        return;
    }

    if (S[idx] == '1') {
        if (idx + 3 >= S.length()) {
            return;
        }
        
        if (S[idx + 1] != '0' || S[idx + 2] != '0') {
            return;
        }

        int i = 3, cntOne = 0;
        while (S[idx + i] == '0' && idx + i < S.length()) {
            i++;
        }
        while (S[idx + i] == '1' && idx + i < S.length()) {
            i++;
            cntOne++;
        }

        if (idx + i >= S.length()) {
            if (cntOne > 0) {
                check = true;
            }
            
            return;
        }

        if (cntOne > 1) {
            Solve(idx + i - 1);
        }
        Solve(idx + i);
    } else {
        if (idx + 1 >= S.length()) {
            return;
        }
        
        if (S[idx + 1] != '1') {
            return;
        }

        Solve(idx + 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;

    Solve(0);

    if (check) {
        cout << "SUBMARINE";
    } else {
        cout << "NOISE";
    }
    
    return 0;
}