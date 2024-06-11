#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;
vector<char> alpha;
int arr[26];
bool visited[10];
int len, answer, temp = 1;

void Dfs(int cnt, char preC) {
    if (cnt == len) {
        answer++;
        return;
    }

    //cout << cnt << "\n";
    for (int i = 0; i < len; i++) {
        if (alpha[i] == preC)
            continue;

        if (visited[i])
            continue;

        visited[i] = true;
        Dfs(cnt + 1, alpha[i]);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    len = S.length();
    for (int i = 0; i < len; i++) {
        alpha.push_back(S[i]);

        arr[S[i] - 'a']++;
        temp *= arr[S[i] - 'a'];
    }

    Dfs(0, '0');

    cout << answer / temp;
    
    return 0;
}