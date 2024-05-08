#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int dice[10000][6];
int opposite[6];

int NextBottom(int i, int up) {
    for (int j = 0; j < 6; j++) {
        if (dice[i][up] == dice[i + 1][j]) {
            return j;
        }
    }

    return 0;
}

int solve(int bottom) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int maxValue = 0, up = opposite[bottom];

        for (int j = 0; j < 6; j++) {
            if (j == bottom || j == up) {
                continue;
            }

            maxValue = max(maxValue, dice[i][j]);
        }

        sum += maxValue;

        bottom = NextBottom(i, up);
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

    opposite[0] = 5;
    opposite[1] = 3;
    opposite[2] = 4;
    opposite[3] = 1;
    opposite[4] = 2;
    opposite[5] = 0;

    for (int i = 0; i < 6; i++) {
        answer = max(answer, solve(i));
    }

    cout << answer;
    
    return 0;
}