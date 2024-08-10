#include <iostream>

using namespace std;

int N, M;
int arr[2001];
int palindrom[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
  
    for (int i = 1; i <= N; i++) {
		palindrom[i][i] = true;
	}
    
    for (int i = 1; i <= N - 1; i++) {
		if (arr[i] == arr[i + 1])
			palindrom[i][i + 1] = true;
	}

	for (int i = N - 2; i >= 1; i--) {
		for (int j = i + 2; j <= N; j++) {  
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true)
				palindrom[i][j] = true;
		}
	}
	
	cin >> M;
    int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << palindrom[s][e] << '\n';
	}
    
    return 0;
}