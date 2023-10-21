#include <iostream>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
	cin >> x;

    // 대각선으로 묶어서 풀이
    // i번째 대각선에는 i개의 원소가 있으므로, x가 몇번째 대각선에 있는지 파악
	int i = 1;
	while (x > i) {
		x -= i;
		i++;
	}

    // 분자를 구한 후, i+1에서 분자를 뺀 값을 분모로 사용
	if (i % 2 == 1) {
        // string으로 바꿀 필요없이 그냥 출력하면 됨
		cout << i + 1 - x << '/' << x << endl;
    } else {
		cout << x << '/' << i + 1 - x << endl;
    }

    return 0;
}