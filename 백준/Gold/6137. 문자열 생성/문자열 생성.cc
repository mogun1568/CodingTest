#include <iostream>
#include <string>
using namespace std;

string S;
int len;

void AddT(int index) {
    cout << S[index];
    
    len++;
    if (len % 80 == 0)
        cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        S += c;
    }

    int start = 0, end = N - 1;
    while (start <= end) {
        if (S[start] < S[end])
            AddT(start++);
        else if (S[start] > S[end])
            AddT(end--);
        else {
            if (start == end) {
                AddT(start);
                break;
            }
            
            int s = start + 1, e = end - 1;
            while (s < e && S[s] == S[e]) {
                s++;
                e--;
            }

            bool pick_start = true;
            if (s < e && S[s] > S[e])
                pick_start = false;

            if (pick_start)
                AddT(start++);
            else
                AddT(end--);
        }
    }
    
    return 0;
}