#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> nickname;

struct Trie {
    Trie* children[26];

    Trie() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }

    void insert(const string& str) {
        Trie* cur = this;
        string result = "";
        bool isFirst = false;
        
        for (char c : str) {
            if (!isFirst)
                result += c;
            
            int idx = c - 'a';
            if (cur -> children[idx] == nullptr) {
                cur -> children[idx] = new Trie();
                isFirst = true;
            }
            cur = cur -> children[idx];
        }

        cout << result;
        if (!isFirst && nickname[str] > 0)
            cout << nickname[str] + 1;
        cout << "\n";
        
        nickname[str]++;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    Trie root;
    string str;
    while (N--) {
        cin >> str;
        root.insert(str);
    }
    
    return 0;
}