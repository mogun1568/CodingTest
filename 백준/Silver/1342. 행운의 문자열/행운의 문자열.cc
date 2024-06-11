#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

bool Check(string s) {
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i])
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    sort(S.begin(), S.end());

    int answer = 0;
	do {
		if (Check(S))
            answer++;
	} while (next_permutation(S.begin(), S.end()));

    cout << answer;
    
    return 0;
}