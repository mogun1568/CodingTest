#include <iostream>
#include <string>

using namespace std;

bool Dfs(string s) {
	bool flag = false;
	int size = s.size();
	if (size == 0) {
        return true;
    }
    
	if (s[0] == '0') {
		if (s[1] == '1') flag |= Dfs(s.substr(2));
    }
	else {
		// 0 구간
		int i = 1;
		while (i < size && s[i] == '0') {
			i++;
		}
		if (i <= 2) {
			return flag;
		}
        
		// 1 구간 
		int j = i;
		while (j < size && s[j] == '1') {
			j++;
		}
        
		// 1이 1개
		if (j == i + 1) {
			flag |= Dfs(s.substr(j));
        }
		// 1이 2개 이상일 때 마지막 1 뒤에 0 개수 확인
		else if (j >= i + 2) {
			if (j == size - 1) {
                return flag;
            }
            
			if (s[j + 1] == '0') {
				flag |= Dfs(s.substr(j - 1));
            } else {
				flag |= Dfs(s.substr(j));
            }
		}
	}
        
	return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    string s;
    while (n--) {
        cin >> s;

        string answer = Dfs(s) ? "YES" : "NO";
        cout << answer << "\n";
    }
    
    return 0;
}