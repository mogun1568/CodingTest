#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<char> result;
    stack<int> s;
    int cnt = 1;
    
    for (int i = 0; i < n; i++) {
        int a;
		cin >> a;
 
		while (cnt <= a)
		{
			s.push(cnt);
			cnt += 1;
			result.push_back('+');
		}
 
		if (s.top() == a) {
			s.pop();
			result.push_back('-');
		} else {
			cout << "NO";
			return 0;
		}
        
    }
    
    for (auto r : result) {
        cout << r << "\n";
    }

    return 0;
}