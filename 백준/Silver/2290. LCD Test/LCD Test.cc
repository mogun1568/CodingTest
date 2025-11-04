#include <iostream>
#include <string>
using namespace std;

int s;
char LCD[10][24][13];

void PrintW(int idx, int r) {
    for (int i = 2; i <= s + 1; i++) 
        LCD[idx][r][i] = '-';
}

void PrintL(int idx, int r, int c) {
    for (int i = r + 1; i <= r + s; i++)
        LCD[idx][i][c] = '|';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> s >> n;

    for (int i = 1; i <= 2 * s + 3; i++) {
        for (int j = 0; j < n.length(); j++) {
            for (int k = 1; k <= s + 2; k++)
                LCD[j][i][k] = ' ';
        }
    }

    for (int i = 0; i < n.length(); i++) {
        switch (n[i]) {
            case '1':
                PrintL(i, 1, s + 2);
                PrintL(i, s + 2, s + 2);
                break;
            case '2':
                PrintW(i, 1);
                PrintL(i, 1, s + 2);
                PrintW(i, s + 2);
                PrintL(i, s + 2, 1);
                PrintW(i, 2 * s + 3);
                break;
            case '3':
                PrintW(i, 1);
                PrintL(i, 1, s + 2);
                PrintW(i, s + 2);
                PrintL(i, s + 2, s + 2);
                PrintW(i, 2 * s + 3);
                break;
            case '4':
                PrintL(i, 1, 1);
                PrintL(i, 1, s + 2);
                PrintW(i, s + 2);
                PrintL(i, s + 2, s + 2);
                break;
            case '5':
                PrintW(i, 1);
                PrintL(i, 1, 1);
                PrintW(i, s + 2);
                PrintL(i, s + 2, s + 2);
                PrintW(i, 2 * s + 3);
                break;
            case '6':
                PrintW(i, 1);
                PrintL(i, 1, 1);
                PrintW(i, s + 2);
                PrintL(i, s + 2, 1);
                PrintL(i, s + 2, s + 2);
                PrintW(i, 2 * s + 3);
                break;
            case '7':
                PrintW(i, 1);
                PrintL(i, 1, s + 2);
                PrintL(i, s + 2, s + 2);
                break;
            case '8':
                PrintW(i, 1);
                PrintL(i, 1, 1);
                PrintL(i, 1, s + 2);
                PrintW(i, s + 2);
                PrintL(i, s + 2, 1);
                PrintL(i, s + 2, s + 2);
                PrintW(i, 2 * s + 3);
                break;
            case '9':
                PrintW(i, 1);
                PrintL(i, 1, 1);
                PrintL(i, 1, s + 2);
                PrintW(i, s + 2);
                PrintL(i, s + 2, s + 2);
                PrintW(i, 2 * s + 3);
                break;
            default:
                PrintW(i, 1);
                PrintL(i, 1, 1);
                PrintL(i, 1, s + 2);
                PrintL(i, s + 2, 1);
                PrintL(i, s + 2, s + 2);
                PrintW(i, 2 * s + 3);
        }
    }

    for (int i = 1; i <= 2 * s + 3; i++) {
        for (int j = 0; j < n.length(); j++) {
            for (int k = 1; k <= s + 2; k++)
                cout << LCD[j][i][k];
            cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}