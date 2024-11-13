#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    map<string, double> m;
    string s;
    while (getline(cin, s)) {
        cnt++;
        m[s]++;
    }

    cout << fixed;
	cout.precision(4);
    for (auto tree : m)
        cout << tree.first << " " << tree.second / cnt * 100 << "\n";
    
    return 0;
}