#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
bool grid[101][101];
vector<int> dir;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void MakeCurve() {
    for (int i = dir.size() - 1; i >= 0; i--) {
        int cd = (dir[i] + 1) % 4;
        y += dy[cd];
        x += dx[cd];
        grid[y][x] = true;
        dir.push_back(cd);
    }
}

int CountSquare() {
    int result = 0;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1])
                result++;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;

        dir.clear();

        grid[y][x] = true;
        y += dy[d];
        x += dx[d];
        grid[y][x] = true;
        dir.push_back(d);

        for (int j = 0; j < g; j++) {
            MakeCurve();
        }
    }

    cout << CountSquare();
    
    return 0;
}