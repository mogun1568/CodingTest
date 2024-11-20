#include <iostream>
#include <string>
using namespace std;

int point1, point2, win;
int goal1, goal2;
int ans1, ans2;

void Solution(int team, string s) {
    size_t colon = s.find(':');
    string min = s.substr(0, colon);
    string sec = s.substr(colon + 1);
    int t = stoi(min) * 60 + stoi(sec); 
    
    if (team == 1) point1++;
    else point2++;

    int curWin = 0;
    if (point1 > point2) curWin = 1;
    else if (point1 < point2) curWin = 2;
    else curWin = 0;

    if (win == 0) {
        if (curWin == 1)
            goal1 = t;
        else if (curWin == 2)
            goal2 = t;
    }
    
    if (curWin == 0) {
        if (win == 1)
            ans1 += t - goal1;
        else if (win == 2)
            ans2 += t - goal2;
    }
        
    win = curWin;       
}

void Print(int ans) {
    int min = ans / 60;
    int sec = ans % 60;

    printf("%02d:%02d\n", min, sec);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, team;
    cin >> N;

    string s;
    while (N--) {
        cin >> team >> s;
        Solution(team, s);
    }

    if (win == 1)
        ans1 += 2880 - goal1;
    else if (win == 2)
        ans2 += 2880 - goal2;

    Print(ans1);
    Print(ans2);
    
    return 0;
}