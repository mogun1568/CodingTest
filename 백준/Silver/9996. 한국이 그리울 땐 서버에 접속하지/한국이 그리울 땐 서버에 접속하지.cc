#include <iostream>
#include <string>
#include <regex>
using namespace std;

int N;
string s, pattern;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> pattern;

    pattern.replace(pattern.find("*"), 1, "\\w*");
    regex re(pattern, regex::optimize);
    
    while (N--) {
        cin >> s;
        
        if (regex_match(s, re))
            cout << "DA\n";
        else
            cout << "NE\n";
    }
    
    return 0;
}