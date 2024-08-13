#include <iostream>
#include <vector>

using namespace std;

int N, M, answer;
int parent[51];
vector<int> truth;
vector<int> party[50];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    answer = M;

    int c, n;
    cin >> c;
    while (c--) {
        cin >> n;
        truth.push_back(n);
    }

    for (int i = 0; i < M; i++) {
        cin >> c;
        while (c--) {
            cin >> n;
            party[i].push_back(n);
        }
    }

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++) {
        int n1 = party[i][0], n2;
        for (int j = 1; j < party[i].size(); j++) {
            n2 = party[i][j];
            Union(n1, n2);
        }
    }

    for (int i = 0; i < M; i++) {
        bool canGo = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (!canGo)
                break;

            int n1 = party[i][j], n2;
            for (int k = 0; k < truth.size(); k++) {
                n2 = truth[k];
                if (Find(n1) == Find(n2)) {
                    canGo = false;
                    break;
                }
            }
        }

        if (!canGo)
            answer--;
    }
    
    cout << answer;
    
    return 0;
}