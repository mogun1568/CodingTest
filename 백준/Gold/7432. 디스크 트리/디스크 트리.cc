#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

struct Trie {
    map<string, Trie*> children;

    ~Trie() {
        for (auto& pair : children)
            delete pair.second;
    }

    void insert(string str) {
        Trie* cur = this;
        istringstream iss(str);
        string word;

        while (getline(iss, word, '\\')) {
            if (cur -> children.find(word) == cur -> children.end())
                cur -> children[word] = new Trie();
            cur = cur -> children[word];
        }
    }

    void print(int depth) {
        for (const auto& pair : children) {
            string word = pair.first;
            Trie* next = pair.second;

            for (int i = 0; i < depth; i++)
                cout << " ";
            cout << word << "\n";

            next -> print(depth + 1);
        }
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

    root.print(0);
    
    return 0;
}