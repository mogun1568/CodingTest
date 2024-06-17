#include <iostream>

using namespace std;

#define MAX 100001

int A, B, answer;
int prime[MAX];

void CheckPrime() {
    for (int i = 2; i < MAX; i++) {
        if (prime[i] != 0) {
            continue;
        }
        
        prime[i] = 1;
        for (int j = i + i; j < MAX; j += i) {
            prime[j] = prime[j / i] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;

    CheckPrime();

    for (int i = A; i <= B; i++) {
        if (prime[prime[i]] == 1) {
            answer++;
        }
    }

    cout << answer;
    
    return 0;
}