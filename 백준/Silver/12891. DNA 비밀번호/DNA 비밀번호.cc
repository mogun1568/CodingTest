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

    int i;
    for (i = 0; i < P; i++)
        alpha[dna[i] - 'A']++;
    
    if (alpha['A' - 'A'] >= A && alpha['C' - 'A'] >= C && alpha['G' - 'A'] >= G && alpha['T' - 'A'] >= T)
            ans++;

    for (i; i < S; i++) {
        alpha[dna[i] - 'A']++;
        alpha[dna[i - P] - 'A']--;

        if (alpha['A' - 'A'] >= A && alpha['C' - 'A'] >= C && alpha['G' - 'A'] >= G && alpha['T' - 'A'] >= T)
            ans++;
    }

    cout << ans;
    
    return 0;
}