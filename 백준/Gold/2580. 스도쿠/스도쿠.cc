#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int board[9][9];
vector<pair<int, int>> zero;
bool isPossible[10][3];    // 행, 열, 사각형
bool success;
    

void Print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void Dfs(int idx) {
    if (success)
        return;
    
    if (idx >= zero.size()) {
        success = true;
        Print();
        return;
    }
    
    int r = zero[idx].first;
    int c = zero[idx].second;
    memset(isPossible, false, sizeof(isPossible));

    for (int i = 0; i < 9; i++) {
        isPossible[board[i][c]][0] = true;
        isPossible[board[r][i]][1] = true;
    }

    int rStart = r / 3 * 3;
    int cStart = c / 3 * 3;
    for (int i = rStart; i < rStart + 3; i++) {
        for (int j = cStart; j < cStart + 3; j++) {
            isPossible[board[i][j]][2] = true;
        }
    }

    vector<int> v;
    for (int i = 1; i <= 9; i++) {
        if (!isPossible[i][0] && !isPossible[i][1] && !isPossible[i][2])
            v.push_back(i);
    }

    if (v.empty())
        return;

    for (int i = 0; i < v.size(); i++) {
        board[r][c] = v[i];
        Dfs(idx + 1);
        board[r][c] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0)
                zero.push_back({i, j});
        }
    }

    Dfs(0);
    
    return 0;
}