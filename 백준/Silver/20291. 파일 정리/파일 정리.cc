#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s;
    cin >> N;

    map<string, int> m;

    while (N--) {
        cin >> s;

        size_t dot = s.find('.');
        m[s.substr(dot + 1)]++;
    }

    for (auto i : m)
        cout << i.first << " " << i.second << "\n";
    
    return 0;
}