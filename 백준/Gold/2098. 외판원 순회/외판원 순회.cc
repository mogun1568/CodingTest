#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int N;
int map[16][16];
int dp[16][1 << 16];

int Tsp(int cur, int visited) {
    // 모든 노드를 방문했는데 
	if(visited == (1 << N) - 1){
		// 현재 노드에서 0번으로 가는 경로가 있으면 
		if(map[cur][0] > 0){ 
			return map[cur][0]; // 최소 비용 반환 
		}

		return INF; // 불가능한 경우에는 INF 반환 
	}

	// 현재 상태를 이미 계산한 값이 dp 테이블에 있다면 그대로 사용
	if(dp[cur][visited] != 0) return dp[cur][visited];

	// 없으면 현재 노드에 대한 탐색 진행 
	dp[cur][visited] = INF; 
    
	for(int i = 0; i < N; i++){
		// 현재 노드에서 i번 노드로 가는 경로가 없으면 패스
		if(map[cur][i] == 0) continue;
        
		// 이미 방문한 노드면 패스 
		if(visited & (1 << i)) continue;

		// i번 노드 방문 처리 후 최소 비용 반환 
		int temp = Tsp(i, visited | 1 << i); 
		dp[cur][visited] = min(dp[cur][visited], map[cur][i] + temp); 
	}

	return dp[cur][visited]; // 최소 비용 반환 
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    cout << Tsp(0, 1);
    
    return 0;
}