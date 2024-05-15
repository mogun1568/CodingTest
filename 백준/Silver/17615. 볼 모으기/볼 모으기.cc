#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, answer = 500000;
string S;

void Front(char c, int idx) {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == c) {
            if (i - idx != 1) {
                cnt++;
            }
            idx++;
        }
    }

    answer = min(answer, cnt);
}

void Back(char c, int idx) {
    int cnt = 0;
    
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == c) {
            if (idx - i != 1) {
                cnt++;
            }
            idx--;
        }
    }

    answer = min(answer, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;

    Front('R', -1);
    Front('B', -1);
    Back('R', N);
    Back('B', N);

    cout << answer;
    
    return 0;
}