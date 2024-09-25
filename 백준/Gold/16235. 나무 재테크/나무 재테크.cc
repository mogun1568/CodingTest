#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, answer;
int ground[11][11];
int A[11][11];
vector<int> tree[11][11];

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Season() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 봄
            if (tree[i][j].empty())
                continue;

            vector<int> v;
            int amount = 0;
            for (int k = tree[i][j].size() - 1; k >= 0; k--) {
                int age = tree[i][j][k];
                
                if (ground[i][j] - age >= 0) {
                    ground[i][j] -= age;
                    v.push_back(age + 1);
                } 
                else
                    amount += age / 2;
            }
            tree[i][j].clear();
            
            for (int k = v.size() - 1; k >= 0; k--)
                tree[i][j].push_back(v[k]);

            // 여름
            ground[i][j] += amount;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 겨울
            ground[i][j] += A[i][j];

            // 가을
            if (tree[i][j].empty())
                continue;

            for (int k = 0; k < tree[i][j].size(); k++) {
                int age = tree[i][j][k];
                
                if (age % 5 != 0)
                    continue;

                for (int l = 0; l < 8; l++) {
                    int nr = i + dr[l];
                    int nc = j + dc[l];

                    if (nr < 1 || nr > N || nc < 1 || nc > N)
                        continue;

                    tree[nr][nc].push_back(1);
                }
            }
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            ground[i][j] = 5;
        }
    }

    vector<pair<int, pair<int, int>>> v;
    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        v.push_back({z, {x, y}});
    }
    sort(v.begin(), v.end());

    for (int i = M - 1; i >= 0; i--) {
        x = v[i].second.first;
        y = v[i].second.second;
        z = v[i].first;
        tree[x][y].push_back(z);
    }

    while (K--)
        Season();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            answer += tree[i][j].size();
        }
    }

    cout << answer;
    
    return 0;
}