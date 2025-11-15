#include <iostream>
using namespace std;

const long long MOD = 1000000000;

// DP[길이][마지막 숫자][비트마스크]
long long DP[101][10][1 << 10]; // 1 << 10은 1024입니다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 1. 초기화 (Base Case: 길이가 1일 때)
    // 0으로 시작할 수 없으므로 1~9까지만 초기화합니다.
    for (int j = 1; j <= 9; j++)
        DP[1][j][1 << j] = 1;   // [길이 1][끝숫자 j][j만 사용한 비트마스크] = 1가지

    // 2. DP 점화식 (길이 2부터 N까지)
    for (int i = 2; i <= N; i++) {
        // j: 이전 상태(길이 i-1)의 마지막 숫자
        for (int j = 0; j <= 9; j++) {
            // k: 이전 상태(길이 i-1)의 비트마스크
            for (int k = 0; k < (1 << 10); k++) {
                // 이전 상태(i-1)에서 (j로 끝나고 k 비트마스크)인 경우가 없으면 건너뜀
                if (DP[i-1][j][k] == 0)
                    continue;

                // 2-1. 다음 숫자가 j-1인 경우
                if (j > 0) {
                    int next_digit = j - 1;
                    // k (현재까지 사용한 숫자 집합)에 next_digit (새로 사용한 숫자)를 추가합니다.
                    int next_mask = k | (1 << next_digit);
                    
                    DP[i][next_digit][next_mask] = (DP[i][next_digit][next_mask] + DP[i-1][j][k]) % MOD;
                }
                
                // 2-2. 다음 숫자가 j+1인 경우
                if (j < 9) {
                    int next_digit = j + 1;
                    // k (현재까지 사용한 숫자 집합)에 next_digit (새로 사용한 숫자)를 추가합니다.
                    int next_mask = k | (1 << next_digit);

                    DP[i][next_digit][next_mask] = (DP[i][next_digit][next_mask] + DP[i-1][j][k]) % MOD;
                }
            }
        }
    }

    // 3. 최종 결과 계산
    int ans = 0;
    // 모든 숫자를 사용한 비트마스크 (0~9)
    int all_digits_mask = (1 << 10) - 1; // 1111111111 (2진수)

    // 길이가 N이고, 모든 숫자를 사용한(mask == 1023) 경우의 수를 모두 더함
    for (int j = 0; j <= 9; j++)
        ans = (ans + DP[N][j][all_digits_mask]) % MOD;

    cout << ans;

    return 0;
}