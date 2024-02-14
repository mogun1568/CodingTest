#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        string p, x;
        int n;
        cin >> p >> n >> x;

        deque<int> dq;
        
        x = x.substr(1, x.length() - 2);
        istringstream ss(x);
        string temp;
        while (getline(ss, temp, ',')) {
            dq.push_back(stoi(temp));
        }

        bool front = true, check = false;
        for (auto f : p) {
            if (f == 'R') {
                front = !front;
            } else {
                if (dq.empty()) {
                    cout << "error\n";
                    check = true;
                    break;
                }
                
                if (front) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }

        if (!check) {
            cout << '[';
            int i, len = dq.size();
            if (front) {
                for (i = 0; i < len - 1; i++) {
                    cout << dq[i] << ',';
                }
            } else {
                for (i = len - 1; i > 0; i--) {
                    cout << dq[i] << ',';
                }
            }
            if (!dq.empty()) {
                cout << dq[i];
            }
            cout << "]\n";
        }
    }
    
    return 0;
}