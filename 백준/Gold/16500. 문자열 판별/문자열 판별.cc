#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool dp[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S, A;
    int N;
    cin >> S >> N;

    vector<string> v;
    for (int i = 0; i < N; i++) {
        cin >> A;
        v.push_back(A);
    }

    for (int i = 0; i < S.length(); i++) {
        if (i != 0 && !dp[i])
            continue;

        for (auto a : v) {
            if (i + a.length() > S.length())
                continue;

            if (a == S.substr(i, a.length()))
                dp[i + a.length()] = true;
        }
    }

    if (dp[S.length()])
        cout << 1;
    else
        cout << 0;
    
    return 0;
}