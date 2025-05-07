#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, n;
    string p, arr;

    cin >> T;
    while (T--) {
        cin >> p >> n >> arr;

        deque<int> dq;
        bool check = false, isFront = true;
        string temp = "";
        for (int i = 1; i < arr.length(); i++) {
            if (arr[i] == ',' || arr[i] == ']') {
                if (temp != "") {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }               
            else
                temp += arr[i];
        }

        for (auto i : p) {
            if (i == 'R')
                isFront = !isFront;
            else {
                if (dq.empty()) {
                    check = true;
                    cout << "error\n";
                    break;
                }
                
                if (isFront)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (!check) {
            int i, len = dq.size();
            
            cout << '[';
            if (isFront) {
                for (i = 0; i < len - 1; i++)
                    cout << dq[i] << ',';
            }
            else {
                for (i = len - 1; i > 0; i--)
                    cout << dq[i] << ',';
            }
            if (!dq.empty())
                cout << dq[i];
            cout << "]\n";  
        }
    }
    
    return 0;
}