#include <iostream>
#include <string>
using namespace std;

struct Trie {
	Trie* node[26];

	Trie() {
		for (int i = 0; i < 26; i++)
            node[i] = NULL;
	}

	void insert(string& str, int idx) {
		if (idx == str.size())
			return;

		if (node[str[idx] - 'a'] == NULL)
			node[str[idx] - 'a'] = new Trie();
			
		node[str[idx] - 'a'] -> insert(str, idx + 1);
	}

	bool find(string& str, int idx) {
		if (idx == str.size())
			return true;

		if (node[str[idx] - 'a'] == NULL)
			return false;

		return node[str[idx] - 'a'] -> find(str, idx + 1);
	}

	void clear(void) {
		for (int i = 0; i < 26; i++) {
			if (node[i] != NULL) {
				node[i] -> clear();
				delete node[i];
			}
		}
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	Trie* root = new Trie();
    string str;
	while (N--) {
		cin >> str;
		root -> insert(str, 0);
	}

	int ans = 0;
	while (M--) {
		cin >> str;
		if (root -> find(str, 0))
			ans++;
	}

	cout << ans << '\n';
    
	root -> clear();
	delete root;
    
	return 0;
}