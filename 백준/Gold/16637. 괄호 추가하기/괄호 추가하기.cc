#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, ans = -2147483647;
string expr;

int calculate(int a, int b, char op) {
	switch(op) {
		case '+':
			a += b; 
			break;
		case '-':
			a -= b;
			break;
		case '*':
			a *= b;
			break;
	}
	
	return a;
}

void DFS(int idx, int cur) {
    if (idx >= N) {
        ans = max(ans, cur);
        return;
    }

    char op = idx == 0 ? '+' : expr[idx - 1];
    
    if(idx + 2 < N) {
		int bracket = calculate(expr[idx] - '0', expr[idx + 2] - '0', expr[idx + 1]);
		DFS(idx + 4, calculate(cur, bracket, op));
	}
	
	DFS(idx + 2, calculate(cur, expr[idx] - '0', op));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> expr;

    DFS(0, 0);

    cout << ans;
    
    return 0;
}