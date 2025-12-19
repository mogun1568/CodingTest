#include <iostream>
#include <algorithm>
using namespace std;

int playerResult[50][9];
int players[8] = {1, 2, 3, 4, 5, 6, 7, 8}; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++)
            cin >> playerResult[i][j];
    }

    int ans = 0;
    do {
        int hitters[9];
        int temp = 0;
        for (int i = 0; i < 9; i++) {
            if (i == 3) {
                hitters[i] = 0;
                temp++;
            }
            else
                hitters[i] = players[i - temp];
        }

        int score = 0, inning = 0, hitterIdx = 0;
        while (inning < N) {
            bool base[4] = {false, };

            int out = 0;
            while (out < 3) {
                int curHitter = hitters[hitterIdx];
                hitterIdx = (hitterIdx + 1) % 9;

                int baseCnt = playerResult[inning][curHitter];
                if (baseCnt == 0)
                    out++;
                else {
                    if (base[3]) {
                        score++;
                        base[3] = false;
                    }
                    if (base[2]) {
                        if (2 + baseCnt > 3)
                            score++;
                        else
                            base[2 + baseCnt] = true;
                        base[2] = false;
                    }
                    if (base[1]) {
                        if (1 + baseCnt > 3)
                            score++;
                        else
                            base[1 + baseCnt] = true;
                        base[1] = false;
                    }
                    if (baseCnt > 3)
                        score++;
                    else
                        base[baseCnt] = true;
                }
            }
            
            inning++;
        }

        ans = max(ans, score);
    } while (next_permutation(players, players + 8));

    cout << ans;
    
    return 0;
}