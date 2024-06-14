#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string word[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }
    sort(word, word + N);

    int answer = N;
    for (int i = 1; i < N; i++) {
        string temp = word[i].substr(0, word[i - 1].size());
        if(temp == word[i - 1])
          answer--;
    }

    cout << answer;
    
    return 0;
}