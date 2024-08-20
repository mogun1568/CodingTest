#include <iostream>

using namespace std;

long long N, B;
long long matrix[5][5];
long long answer[5][5];

void multi_matrix(long long matrix1[5][5], long long matrix2[5][5]) {
	long long tmp[5][5];

	// 행렬 곱 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long sum = 0;

			for (int k = 0; k < N; k++) {
				sum += matrix1[i][k] * matrix2[k][j];
			}

			tmp[i][j] = sum % 1000;
		}
	}

	// 임시행렬 값을 matrix1에 덮어 씌우기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrix1[i][j] = tmp[i][j];
}

void Solution() {
	while (B > 0) {
		// 홀수일 경우, ans와 matrix 곱
		if (B % 2 == 1)
			multi_matrix(answer, matrix);

		// matrix 거듭제곱
		multi_matrix(matrix, matrix);
		B /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
        answer[i][i] = 1;
    }

    Solution();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
    
	return 0;
}