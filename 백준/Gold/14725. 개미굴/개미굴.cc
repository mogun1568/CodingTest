#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Trie {
    map<string, Trie*> m;
};

void DFS(Trie* node, int level) {
    for (auto child : node -> m) 
    {
        for (int i = 0; i < level; i++) 
            cout << "--";
        
        cout << child.first << "\n";
        DFS(child.second, level + 1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    Trie* root = new Trie();

    while (N--)
    {
        int K;
        cin >> K;
        vector<string> arr(K);

        for (int i = 0; i < K; i++) 
            cin >> arr[i];

        Trie* temp = root;

        for (const auto& str : arr) 
        {
            if (temp -> m.count(str) == 0) 
                temp -> m[str] = new Trie();
            
            temp = temp -> m[str];
        }
    }

    DFS(root, 0);
}