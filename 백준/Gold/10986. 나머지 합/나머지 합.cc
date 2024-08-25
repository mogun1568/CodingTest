#include <iostream>

using namespace std;

long long N, M, answer;
long long sumMod[1000001];
long long cnt[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> sumMod[i];
        sumMod[i] += sumMod[i - 1];
        sumMod[i] %= M;
    }

    for (int i = 1; i <= N; i++) {
        if (sumMod[i] == 0) {
            cnt[i] = 1;
            for (int j = i - 1; j > 0; j--) {
                if (sumMod[j] == sumMod[i]) {
                    cnt[i] += cnt[j];
                    break;
                }
            }
        }
        else {
            for (int j = i - 1; j > 0; j--) {
                if (sumMod[j] == sumMod[i]) {
                    cnt[i] = cnt[j] + 1;
                    break;
                }
            }
        }

        answer += cnt[i];
    }

    cout << answer;
    
    return 0;
}