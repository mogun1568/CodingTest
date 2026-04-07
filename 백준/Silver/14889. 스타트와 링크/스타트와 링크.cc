#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, ans = 2e9;
int stat[21][21];
bool team[21];

int CompareStat() {
    int start = 0, link = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (team[i] && team[j])
                start += stat[i][j];
            else if (!team[i] && !team[j])
                link += stat[i][j];
        }
    }

    return abs(start - link);
}

void CreateTeam(int idx, int cnt) {
    if (cnt == N / 2)
        ans = min(ans, CompareStat());

    for (int i = idx; i < N; i++) {
        team[i] = true;
        CreateTeam(i + 1, cnt + 1);
        team[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> stat[i][j];
    }

    CreateTeam(0, 0);

    cout << ans;
    
    return 0;
}