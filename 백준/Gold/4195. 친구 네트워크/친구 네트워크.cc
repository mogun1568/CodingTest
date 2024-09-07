#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX 200002

int T, F;
int parent[MAX];
int friendCnt[MAX];
unordered_map<string, int> umap;

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y) {
        parent[y] = x;
        friendCnt[x] += friendCnt[y];
    }
    else if (x > y) {
        parent[x] = y;
        friendCnt[y] += friendCnt[x];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> T;
    while (T--) {
        for (int i = 1; i < MAX; i++) {
            parent[i] = i;
            friendCnt[i] = 1;
        }
        umap.clear();

        int num = 1;
        string a, b;

        cin >> F;
        for (int i = 0; i < F; i++) {
            cin >> a >> b;

            if (umap[a] == 0)
                umap[a] = num++;
            if (umap[b] == 0)
                umap[b] = num++;

            Union(umap[a], umap[b]);

            int root = Find(umap[a]); 

            cout << friendCnt[root] << "\n";
        }
    }
    
    return 0;
}