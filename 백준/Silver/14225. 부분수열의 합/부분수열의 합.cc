#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2000001

int n;
int s[21];
bool visited[MAX];

void dfs(int idx, int sum)
{
	if (idx == n) {
		visited[sum] = true;
		return;
	}
    
	dfs(idx + 1, sum);
    dfs(idx + 1, sum + s[idx]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    dfs(0, 0);

    for (int i = 1; i < MAX; i++) {
        if (!visited[i]) {
            cout << i;
            break;
        }
    }
    
    return 0;
}