#include <iostream>
#include <string>
using namespace std;

int S, P, A, C, G, T, ans;
string dna;
int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> P >> dna >> A >> C >> G >> T;

    for (int i = 0; i < S; i++) {
        alpha[dna[i] - 'A']++;
        
        if (i < P - 1) 
            continue;

        if (i > P - 1)
            alpha[dna[i - P] - 'A']--;

        if (alpha['A' - 'A'] >= A && alpha['C' - 'A'] >= C && alpha['G' - 'A'] >= G && alpha['T' - 'A'] >= T)
            ans++;
    }
    
    cout << ans;
    
    return 0;
}