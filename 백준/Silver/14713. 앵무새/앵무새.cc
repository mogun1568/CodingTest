#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

queue<string> q[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    string sentence, word;
    for (int i = 0; i < N; i++) {
        getline(cin, sentence);
        istringstream ss(sentence);
        while (getline(ss, word, ' ')) {
            q[i].push(word);
        } 
    }

    bool check;
    getline(cin, sentence);
    istringstream ss(sentence);
    while (getline(ss, word, ' ')) {
        check = false;
        
        for (int i = 0; i < N; i++) {
            if (q[i].empty())
                continue;
            
            if (word == q[i].front()) {
                q[i].pop();
                check = true;
                break;
            }
        }

        if (!check) {
            cout << "Impossible";
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!q[i].empty()) {
            cout << "Impossible";
            return 0;
        }
    }
    
    cout << "Possible";
    
    return 0;
}