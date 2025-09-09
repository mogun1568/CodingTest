#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string str = "";
        while (N--) {
            char c;
            cin >> c;

            if (c <= str.front())
                str = c + str;
            else
                str += c;
        }

        cout << str << "\n";
    }
    
    return 0;
}