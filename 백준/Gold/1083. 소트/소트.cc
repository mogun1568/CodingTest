#include <iostream>

using namespace std;

int N, S;
int arr[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> S;

    for (int i = 0; i < N && S > 0; i++) {
		int idx = i, m = arr[i];
        
		for (int j = i + 1; j < N && j - i <= S; j++) {
			if (arr[j] > m) {
				m = arr[j];
				idx = j;
			}
		}

		if (idx != i) {
			S -= (idx - i);
            
			for (int j = idx; j > i; j--) {
				arr[j] = arr[j - 1];
			}
            
			arr[i] = m;
		}		
	}
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}