#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    string ns = "";
    for (auto s : str) {
        if (s == '+' || s == '-')
            cout << s;
        else if (s == 'x') {
            int n = stoi(ns) / 2;
            ns = "";
            
            if (n != 1)
                cout << n;
            cout << "xx";
        }
        else
            ns += s;
    }

    if (ns == "0")
        cout << 'W';
    else if (ns == "1")
        cout << "x+W";
    else if (ns != "")
        cout << ns << "x+W";
    else
        cout << "+W";
    
    return 0;
}