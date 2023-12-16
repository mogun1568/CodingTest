#include <iostream>
#include <algorithm>

using namespace std;

int k;
char sign[9];
bool check[10];
string maxNum = "", minNum = "9876543210";

bool signCheck(string num) {
    for (int i = 0; i < k; i++) {
        if (sign[i] == '<') {
            if (num[i] > num[i + 1]) {
                return false;
            }
        } else {
            if (num[i] < num[i + 1]) {
                return false;
            }
        }
    }

    return true;
}

void dfs(string num, int idx) {
    if (idx == k + 1) {
        if (signCheck(num)) {
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (check[i]) {
            continue;
        }
        
        check[i] = true;
        dfs(num + to_string(i), idx + 1);
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }

    dfs("", 0);

    cout << maxNum << "\n" << minNum;
    
    return 0;
}