#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int base36[36][55];
int arr[36][55];
vector<pair<string, int>> p;
int z[55];

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.first > b.first;
}

void Init(string s) {
    for (int i = 0; i < s.length(); i++) {
        int idx = s.length() - i - 1;
        if (s[idx] >= 'A')
            base36[s[idx] - 'A' + 10][i]++;
        else
            base36[s[idx] - '0'][i]++;
    }
}

void Solution2(int i) {
    for (int j = 0; j < 54; j++) {
        int temp = j;
        base36[35][temp] += base36[i][temp];
        base36[i][temp] = 0;
        
        while (base36[35][temp] > 35) {
            base36[35][temp + 1] += base36[35][temp] / 36;
            base36[35][temp] %= 36;
            temp++;
        }
    }
}

void Solution() {
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 50; j++) {
            int temp = j;
            arr[i][temp] += (35 - i) * base36[i][j];
            
            while (arr[i][temp] > 35) {
                arr[i][temp + 1] += arr[i][temp] / 36;
                arr[i][temp] %= 36;
                temp++;
            }   
        }

        string s = "";
        int flag = false;
        for (int j = 54; j >= 0; j--) {
            if (arr[i][j] != 0)
                flag = true;
            
            if (arr[i][j] > 9)
                s += arr[i][j] + 'A' - 10;
            else
                s += arr[i][j] + '0';
        }

        if (flag)
            p.push_back({s, i});
    }

    sort(p.begin(), p.end(), cmp);
    
    int cnt = 0;
    for (auto i : p) {
        if (cnt == K)
            break;

        Solution2(i.second);
        cnt++;
    }
}

void Solution3() {
    for (int i = 0; i < 54; i++) {
        for (int j = 0; j < 36; j++)
            z[i] += base36[j][i] * j;

        int temp = i;
        while (z[temp] > 35) {
            z[temp + 1] += z[temp] / 36;
            z[temp] %= 36;
            temp++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        Init(s);
    }
    cin >> K;
    
    Solution();
    Solution3();
    
    string ans = "";
    bool flag = false; 
    for (int i = 54; i >= 0; i--) {
        if (z[i] != 0)
            flag = true;

        if (!flag)
            continue;
        
        if (z[i] > 9)
            ans += z[i] + 'A' - 10;
        else
            ans += z[i] + '0';
    }

    if (ans == "")
        ans = "0";
    
    cout << ans;
    
    return 0;
}