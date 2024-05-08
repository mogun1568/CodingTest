#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int dice[10000][6];

int FindIdx(int i, int idx) {
    for (int j = 0; j < 6; j++) {
        if (dice[i][idx] == dice[i + 1][j]) {
            return j;
        }
    }

    return 0;
}

int solve(int idx) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int maxValue = 0, a = 0, b = 0;
        
        if (idx == 0) {
            a = 0;
            b = 5;
            idx = 5;
        } else if (idx == 1) {
            a = 1;
            b = 3;
            idx = 3;
        } else if (idx == 2) {
            a = 2;
            b = 4;
            idx = 4;
        } else if (idx == 3) {
            a = 1;
            b = 3;
            idx = 1;
        } else if (idx == 4) {
            a = 2;
            b = 4;
            idx = 2;
        } else {
            a = 0;
            b = 5;
            idx = 0;
        }

        for (int j = 0; j < 6; j++) {
            if (j == a || j == b) {
                continue;
            }

            maxValue = max(maxValue, dice[i][j]);
        }

        sum += maxValue;

        idx = FindIdx(i, idx);
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    for (int i = 0; i < 6; i++) {
        answer = max(answer, solve(i));
    }

    cout << answer;
    
    return 0;
}