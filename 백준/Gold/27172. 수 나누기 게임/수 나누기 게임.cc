#include <iostream>

using namespace std;

int N;
int card[100000], point[1000001];
bool check[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> card[i];
        check[card[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = card[i] * 2; j < 1000001; j += card[i]) {
            if (check[j]) {
                point[card[i]]++;
                point[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << point[card[i]] << " ";
    }
    
    return 0;
}