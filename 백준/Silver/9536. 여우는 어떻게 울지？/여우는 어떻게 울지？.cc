#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N >> ws;

    while (N--) {
        string str, cry;
        getline(cin, str);

        set<string> s;
        while (getline(cin, cry) && cry != "what does the fox say?") {
            istringstream iss(cry);
            iss >> cry >> cry >> cry;
            s.insert(cry); 
        }

        istringstream iss(str);
        while (iss >> cry) {
            if (!s.count(cry))
                cout << cry << " ";
        }
        cout << "\n";
    }
    
    return 0;
}