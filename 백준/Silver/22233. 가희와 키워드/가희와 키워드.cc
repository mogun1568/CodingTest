#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    string s;
    unordered_set<string> us;
    while (N--) {
        cin >> s;
        us.insert(s);
    }

    while (M--) {
        cin >> s;
        istringstream ss(s);
        string temp;

        while (getline(ss, temp, ',')){
            auto it = us.find(temp);
            if(it != us.end())
                us.erase(it);
        }

        cout << us.size() << "\n";
    }
    
    return 0;
}