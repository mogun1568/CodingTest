#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

string s;
vector<pair<int, int>> par;
bool flag[10];
set<string> ans;

void CheckPar() {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            par.push_back({st.top(), i});
            st.pop();
        }
    }
}

void RemovePar() {
    string temp = "";
    vector<int> idx;

    for (int i = 0; i < par.size(); i++) {
        if (!flag[i])
            continue;

        idx.push_back(par[i].first);
        idx.push_back(par[i].second);
    }

    if (idx.empty())
        return;
    sort(idx.begin(), idx.end());

    temp = s.substr(0, idx.front());
    for (int i = 1; i < idx.size(); i++)
        temp += s.substr(idx[i - 1] + 1, idx[i] - idx[i - 1] - 1);
    temp += s.substr(idx.back() + 1);

    ans.insert(temp);
}

void Dfs(int idx) {
    if (idx == par.size()) {
        RemovePar();
        return;
    }

    Dfs(idx + 1);
    flag[idx] = true;
    Dfs(idx + 1);
    flag[idx] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    CheckPar();
    Dfs(0);

    for (auto i : ans)
        cout << i << "\n";
    
    return 0;
}