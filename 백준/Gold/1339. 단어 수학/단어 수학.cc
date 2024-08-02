#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N, answer;
int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    string s;
    while(N--) {
        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'A';
            alpha[idx] += pow(10, s.length() - 1 - i);
        }
    }

    sort(alpha, alpha + 26, greater<int>());

    int idx = 0, a = 9;
    while (alpha[idx] > 0) {
        answer += alpha[idx] * a;
        idx++;
        a--;
    }

    cout << answer;
    
    return 0;
}