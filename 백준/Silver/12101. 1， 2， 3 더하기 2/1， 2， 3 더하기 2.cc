#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
vector<string> v;
bool check;

void Dfs(string s, int sum) {
    if (sum == N) {
        v.push_back(s);
        return;
    }
    else if (sum > N) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (s == "") {
            Dfs(to_string(i), i);
        }
        else {
            Dfs(s + "+" + to_string(i), sum + i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    Dfs("", 0);
    sort(v.begin(), v.end());

    if (K > v.size()) {
        cout << -1;
    }

    for (int i = 0; i < v.size(); i++) {
        if (i + 1 == K) {
            cout << v[i];
            break;
        }
    }
    
    return 0;
}