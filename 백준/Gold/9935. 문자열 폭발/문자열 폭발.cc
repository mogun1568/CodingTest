#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S, B;
vector<char> answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S >> B;

    int bLen = B.length();
    for (int i = 0; i < S.length(); i++) {
        answer.push_back(S[i]);

        if (answer.size() >= bLen) {
            bool check = true;
            for (int j = 0; j < bLen; j++) {
                if (answer[answer.size() - bLen + j] != B[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int j = 0; j < bLen; j++) {
                    answer.pop_back();
                }
            }
        }
    }

    if (answer.empty())
        cout << "FRULA";
    else {
        for (char c : answer) {
            cout << c;
        }
    }

    return 0;
}
