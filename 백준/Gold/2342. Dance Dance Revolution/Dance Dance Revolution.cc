#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> arr;
int DP[100001][5][5];

int getCost(int cur, int next)
{
	if (cur == 0) // 0에서 이동할 때
        return 2;	
	if (cur == next) // 동일한 위치로 이동할 때
        return 1;	
	if (abs(cur - next) == 2) // 반대편으로 이동할 때
        return 4;	
	return 3; // 인접한 위치로 이동할 때
}

int solve(int idx, int left, int right) {
    if (idx == arr.size())
        return 0;
    
    if (DP[idx][left][right] != -1)
        return DP[idx][left][right];

    int moveLeft = solve(idx + 1, arr[idx], right) + getCost(left, arr[idx]);
    int moveRight = solve(idx + 1, left, arr[idx]) + getCost(right, arr[idx]);

    return DP[idx][left][right] = min(moveLeft, moveRight);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
    
        arr.push_back(n);
    }
        
    memset(DP, -1, sizeof(DP));
    
    cout << solve(0, 0, 0);
    
    return 0;
}