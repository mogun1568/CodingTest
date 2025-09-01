#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    vector<string> groups;
    stringstream ss(str);
    string group;

    while (getline(ss, group, ':')) {
        if (!groups.empty() && groups.back() == "" && group == "")
            continue;
        groups.push_back(group);
    }

    for (int i = 0; i < groups.size(); i++) {
        if (i > 0) cout << ":";
        if (groups[i] == "") {
            for (int j = 0; j < 9 - groups.size(); j++) {
                if (j > 0) cout << ":";
                cout << "0000";
            }
        }
        else {
            string temp = groups[i];
            temp.insert(temp.begin(), 4 - temp.length(), '0');
            cout << temp;
        }
    }

    return 0;
}
