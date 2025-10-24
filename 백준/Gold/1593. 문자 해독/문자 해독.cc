#include <iostream>
#include <string>
using namespace std;

int alphaW[58], alphaS[58];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int g, s;
    string W, S;
    cin >> g >> s >> W >> S;

    for (int i = 0; i < g; i++)
        alphaW[W[i] - 'A']++;

    int cnt = 0, ans = 0;
    for (int i = 0; i < g; i++) {
        int cp = S[i] - 'A';
        alphaS[cp]++;

        if (alphaW[cp] != 0 && alphaW[cp] >= alphaS[cp])
            cnt++;
    }
    if (cnt == g)
        ans++;

    for (int i = g; i < s; i++) {
        int cp = S[i - g] - 'A';
        alphaS[cp]--;
        if (alphaW[cp] != 0 && alphaW[cp] > alphaS[cp])
            cnt--;

        cp  = S[i] - 'A';
        alphaS[cp]++;
        if (alphaW[cp] != 0 && alphaW[cp] >= alphaS[cp])
            cnt++;

        if (cnt == g)
            ans++;
    }

    cout << ans;
    
    return 0;
}