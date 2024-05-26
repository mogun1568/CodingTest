#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M, K, answer = 4000000;
bool board[2001][2001];
int Sum[2001][2001];

void Solve(bool b) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            Sum[i][j] = Sum[i][j - 1];
            if (board[i][j] != b) {
                Sum[i][j]++;
            }

            b = !b;
        }

        if (M % 2 == 0) {
            b = !b;
        }  
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            Sum[i][j] += Sum[i - 1][j];
        }
    }
}

void MinValue() {
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            answer = min(answer, Sum[i][j] - Sum[i - K][j] - Sum[i][j - K] +  Sum[i - K][j - K]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j - 1] == 'B') {
                board[i][j] = true;
            }
            else {
                board[i][j] = false;
            }
        }
    }

    Solve(true);
    MinValue();
    Solve(false);
    MinValue();

    cout << answer;
    
    return 0;
}