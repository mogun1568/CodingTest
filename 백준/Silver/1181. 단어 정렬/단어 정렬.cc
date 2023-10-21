#include <iostream>
#include <set>
#include <string>

using namespace std;

// set 정렬을 바꾸려면 구조체 사용해야 함
struct Compare {
	bool operator() (const string &a, const string &b) const {
		if (a.size() == b.size()) {
		    return a < b;
		} else {
		    return a.size() < b.size();
		}
	}
};

int main()
{
    // 입출력 시간 단축
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    set<string, Compare> s;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(tmp);
    }
    
    for (auto i : s) {
        // endl 보다 \n 쓰는 것이 시간이 더 줄어듬
        cout << i << '\n';
    }
    
    return 0;
}