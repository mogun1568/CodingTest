#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<string> words;

bool cheakUse(string word) {
    // 아스키코드를 이용하여 이전에 있던 문자인지 확인
    bool ascii[123] = {false};
    char c = 'A';

    for (int i = 0; i < word.length(); i++) {
        // 앞 문자와 다르고 이전에 썼던 문자이면
        if (word[i] != c && ascii[word[i]]) {
            return false;
        }

        ascii[word[i]] = true;
        c = word[i];
    }

    return true;
}

int main()
{
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        words.push_back(str);
    }

    int cnt = 0;

    for (auto word : words) {
        if (cheakUse(word)) {
            cnt++;
        }
    }

    cout << cnt << endl;
}