#include <iostream>

using namespace std;

int arr[10001];

void dfs(int start, int end) {
	if (start >= end) {
        return;
    }
	
    int i;
	for (i = start + 1; i < end; i++) {
		if(arr[start] < arr[i]) {
            break;
        }
    }
	
	dfs(start + 1, i);
	dfs(i, end);

	cout << arr[start] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, len = 0;

    while (cin >> n) {
        arr[len++] = n;
    }

    dfs(0, len);
    
    return 0;
}