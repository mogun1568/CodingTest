#include <iostream>
#include <vector>
using namespace std;

struct Fireball {
    int m, s, d;
};

int N;
vector<Fireball> grid[51][51];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int get_circular_index(int current, int move, int max_size) {
    int effective_move = move % max_size;
    int result = (current - 1 + effective_move + max_size) % max_size;
    return result + 1;
}

void Solve() {
    vector<Fireball> temp_grid[51][51]; 

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (const auto& fb : grid[i][j]) {
                int nr = get_circular_index(i, dr[fb.d] * fb.s, N);
                int nc = get_circular_index(j, dc[fb.d] * fb.s, N);
                temp_grid[nr][nc].push_back(fb);
            }
            grid[i][j].clear();
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (temp_grid[i][j].empty())
                continue;

            int tSize = temp_grid[i][j].size();
            
            if (tSize == 1) {
                grid[i][j] = temp_grid[i][j];
                continue;
            }

            int sumM = 0, sumS = 0;
            bool odd_dir_exists = false;
            bool even_dir_exists = false;
            
            for (const auto& fb : temp_grid[i][j]) {
                sumM += fb.m;
                sumS += fb.s;
                
                if (fb.d % 2 == 0) {
                    even_dir_exists = true;
                } else {
                    odd_dir_exists = true;
                }
            }
            
            sumM /= 5; 
            
            if (sumM == 0) {
                continue;
            }

            sumS /= tSize;

            bool same_parity = (odd_dir_exists && !even_dir_exists) || (!odd_dir_exists && even_dir_exists);
            
            int start_dir;
            if (same_parity) {
                start_dir = 0; 
            } else {
                start_dir = 1;
            }

            for (int k = 0; k < 4; k++) {
                grid[i][j].push_back({sumM, sumS, start_dir + k * 2});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, K;
    cin >> N >> M >> K;

    int r, c, m, s, d;
    while (M--) {
        cin >> r >> c >> m >> s >> d;
        grid[r][c].push_back({m, s, d});
    }

    while (K--)
        Solve();

    long long sum = 0; 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (const auto& fb : grid[i][j])
                sum += fb.m;
        }
    }

    cout << sum << "\n";
    
    return 0;
}