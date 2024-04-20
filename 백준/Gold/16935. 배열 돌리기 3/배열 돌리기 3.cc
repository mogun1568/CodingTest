#include <iostream>

using namespace std;

int n,m,r;
int rem[101][101];
int arr[101][101];
//row == 행  column = 열 
int row,column;


void input() {
	cin >> n >> m >> r;
	row = n;
	column = m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
}

void printArr() {
	for(int i=1; i<=row; i++) {
		for(int j=1; j<=column; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void turnArr(int tmp) {
	if(tmp == 1) {
		for(int i=1; i<=row; i++) {
			for(int j=1; j<=column; j++) {
				rem[i][j] = arr[row-i+1][j];
			}
		}
	}
	else if(tmp == 2) {
		for(int i=1; i<=row; i++) {
			for(int j=1; j<=column; j++) {
				rem[i][j] = arr[i][column-j+1];
			}
		}
	}
	else if(tmp == 3) {
		int tmp = row;
		row = column;
		column = tmp;
		for(int i=1; i<=row; i++) {
			for(int j=1; j<=column; j++) {
				rem[i][j] = arr[column-j+1][i];
			}
		}
	}
	else if(tmp == 4) {
		int tmp = row;
		row = column;
		column = tmp;
		for(int i=1; i<=row; i++) {
			for(int j=1; j<=column; j++) {
				rem[i][j] = arr[j][row-i+1];
			}
		}
	} 
	else if(tmp == 5) {
		for(int i=1; i<=row/2; i++) {
			for(int j=1; j<=column/2; j++) {
				rem[i][j] = arr[row/2+1+i-1][j];
			}
		}
		for(int i=1; i<=row/2; i++) {
			for(int j=column/2+1; j<=column; j++) {
				rem[i][j] = arr[i][j-column/2];
			}
		}
		for(int i=row/2+1; i<=row; i++) {
			for(int j=1; j<=column/2; j++) {
				rem[i][j] = arr[i][j+column/2];
			}
		}
		for(int i=row/2+1; i<=row; i++) {
			for(int j=column/2+1; j<=column; j++) {
				rem[i][j] = arr[i-row/2][j];
			}
		}
	}
	else if(tmp == 6) {
		for(int i=1; i<=row/2; i++) {
			for(int j=1; j<=column/2; j++) {
				rem[i][j] = arr[i][j+column/2];
			}
		}
		for(int i=1; i<=row/2; i++) {
			for(int j=column/2+1; j<=column; j++) {
				rem[i][j] = arr[i+row/2][j];
			}
		}
		for(int i=row/2+1; i<=row; i++) {
			for(int j=1; j<=column/2; j++) {
				rem[i][j] = arr[i-row/2][j];
			}
		}
		for(int i=row/2+1; i<=row; i++) {
			for(int j=column/2+1; j<=column; j++) {
				rem[i][j] = arr[i][j-column/2];
			}
		}
	}
}

void copyArr() {
	for(int i=1; i<=row; i++) {
		for(int j=1; j<=column; j++) {
			arr[i][j] = rem[i][j];
		}
	}
}

void solve() {
	int tmp;
	for(int i=0; i<r; i++) {
		cin >> tmp;
		turnArr(tmp);
		copyArr();
	} 
}


int main() {
	input();
	solve();
	printArr();
	
}