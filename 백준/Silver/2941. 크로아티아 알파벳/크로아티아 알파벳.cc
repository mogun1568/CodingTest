#include <iostream>
#include <string>

using namespace std;

string croatian[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    string word;
    cin >> word;

    int cnt = 0;
    int len = word.length();

    for (int i = 0; i < 8; i++) {
        
        while (word.find(croatian[i]) != string::npos) {
            cnt++;

            size_t idx = word.find(croatian[i]);
            for (int j = 0; j < croatian[i].length(); j++) {
                word[idx + j] = '0';
            }
            len -= croatian[i].length();
        }
    }

    cout << cnt + len << endl;
}