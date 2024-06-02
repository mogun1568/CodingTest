#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int T, K;
string S;
int minAlpha[26], maxAlpha[26];
bool check;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> S >> K;

        queue<int> q[26];
        check = false;
        for (int i = 0; i < 26; i++) {
            minAlpha[i] = 10000;
            maxAlpha[i] = 0;
        }
        
        for (int i = 0; i < S.length(); i++) {
            int a = S[i] - 'a';
            q[a].push(i);
            
            if (q[a].size() == K) {
                check = true;

                minAlpha[a] = min(minAlpha[a], q[a].back() - q[a].front() + 1);
                maxAlpha[a] = max(maxAlpha[a], q[a].back() - q[a].front() + 1);
                q[a].pop();
            }
        }

        if (check) {
            cout << *min_element(minAlpha, minAlpha + 26) << " ";
            cout << *max_element(maxAlpha, maxAlpha + 26) << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    
    return 0;
}