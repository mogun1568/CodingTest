#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<string> v;
    unordered_map<string, vector<int>> um;
    int maxLen = 0, order = 20001;
    string s, ans;
    
    for (int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(s);
        
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            temp += s[j];
            um[temp].push_back(i);

            if (temp.length() > maxLen && um[temp].size() > 1)
                maxLen = temp.length();
        }
    }
    
    for (const auto& [key, value] : um) {
        if (key.length() == maxLen && value.size() > 1) {
            if (value[0] < order) {
                order = value[0];
                ans = key;
            }
        }   
    }
    
    cout << v[um[ans][0]] << "\n";
    cout << v[um[ans][1]];
    
    return 0;
}