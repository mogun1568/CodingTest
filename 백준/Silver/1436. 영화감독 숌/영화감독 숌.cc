#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, num = 665, tmp;
    cin >> n;
    
    while (n > 0) {
        num++;
		tmp = num;

		// 숫자 안에 666이 있는지 확인
		do {
			if (tmp % 1000 == 666) {
				n--;
				break;
			}
			tmp /= 10;    // 일의 자리 제거
		} while (tmp > 0);
	}
    
    cout << num << '\n';
    
    return 0;
}