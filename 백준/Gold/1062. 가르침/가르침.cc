#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, K, answer;
int word[50];

int CanRead(int alpha) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {		
        if ((word[i] & alpha) == word[i])
            cnt++; 
    }

    return cnt;
}

void Dfs(int idx, int cnt, int alpha) {
    if (cnt == K - 5) {
        answer = max(answer, CanRead(alpha));
        return;
    }

    for (int i = idx; i < 26; i++) {
        int temp = 1 << i;
        
        if (alpha & temp)
            continue; 
        
        alpha |= temp;
        Dfs(i + 1, cnt + 1, alpha);
        alpha ^= temp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            word[i] |= 1 << (s[j] - 'a'); 
        }
    }

    if (K < 5) {
        cout << 0;
        return 0;
    }

    int alpha = 0;
    alpha |= 1 << ('a' - 'a'); 
	alpha |= 1 << ('n' - 'a'); 
	alpha |= 1 << ('t' - 'a'); 
	alpha |= 1 << ('i' - 'a'); 
	alpha |= 1 << ('c' - 'a');

    Dfs(0, 0, alpha);

    cout << answer;
    
    return 0;
}