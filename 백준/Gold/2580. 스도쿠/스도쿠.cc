#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> zero;
bool success;

void Print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool Check(int r, int c, int value) {
    for (int i = 0; i < 9; i++) {
        if (board[i][c] == value) return false;
        if (board[r][i] == value) return false;
    }

    int rStart = r / 3 * 3;
    int cStart = c / 3 * 3;
    for (int i = rStart; i < rStart + 3; i++) {
        for (int j = cStart; j < cStart + 3; j++) {
            if (board[i][j] == value) return false;
        }
    }

    return true;
}

void DFS(int idx) {
    if (success)
        return;
    
    if (idx >= zero.size()) {
        success = true;
        Print();
        return;
    }
    
    int r = zero[idx].first;
    int c = zero[idx].second;

    for (int i = 1; i < 10; i++) {
        if (Check(r, c, i)) {
            board[r][c] = i;
            DFS(idx + 1);
            board[r][c] = 0;
        }
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

    DFS(0);
    
    return 0;
}