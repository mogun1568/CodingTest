#include <iostream>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt = 0;
    cin >> n;
    
    // 5의 개수는 2의 개수보다 항상 적기 때문에 5의 개수만 세면 됨
    for (int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
    
    cout << cnt;

    return 0;
}