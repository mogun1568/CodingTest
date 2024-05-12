#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000001

long long A, B, answer;
bool isPrime[MAX];
vector<long long> prime;

void Eratos() {
    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i]) {
            prime.push_back(i);
            
            for (int j = i + i; j < MAX; j += i) {
                isPrime[j] = true;
            }
        }
    }
}

void Solve() {
    for (long long p : prime) {
        long long cur = p;
        
        while (cur <= B / p) {
            cur *= p;
            if (cur >= A) {
                answer++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;

    Eratos();
    Solve();

    cout << answer;
    
    return 0;
}