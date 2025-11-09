#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

const string hr = "--------------------------------------------------------------------------------\n";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string HTML, str;
    while (getline(cin, str)) {
        HTML += str;
        HTML += "\n";
    }

    vector<string> words;
    istringstream iss(HTML);
    string word;
    while (iss >> word)
        words.push_back(word);

    int len = 0;
    for (string w : words) {
        if (w == "<br>") {
            cout << "\n";
            len = 0;
        }
        else if (w == "<hr>") {
            if (len != 0)
                cout << "\n";
            cout << hr;
            len = 0;
        }
        else {
            if (len + w.length() + 1 > 80) {
                cout << "\n";
                len = 0;
            }

            if (len != 0) {
                cout << " ";
                len += 1;
            }

            cout << w;
            len += w.length();
        }
    }
    cout << "\n";
    
    return 0;
}