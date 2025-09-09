#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        deque<char> dq;
        while (N--) {
            char abc;
            cin >> abc;

            if (abc <= dq.front())
                dq.push_front(abc);
            else
                dq.push_back(abc);
        }

        for (char c : dq)
            cout << c;
        cout << "\n";
    }
    
    return 0;
}