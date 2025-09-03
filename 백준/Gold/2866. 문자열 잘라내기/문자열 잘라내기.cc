#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string strs[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++)
            strs[j] += str[j]; 
    }

    int count = 0;
    while (true) {
        unordered_map<string, int> um;
        for (int i = 0; i < C; i++) {
            string temp = strs[i].substr(count);
            um[temp]++;
            
            if (um[temp] > 1) {
                cout << count - 1;
                return 0;
            }
        }

        count++;
    }
    
    return 0;
}