#include <bits/stdc++.h>
using namespace std;

int rowOfNBasedOnS(int s){ return 2 * s + 3; }
int midROW(int ROW){ return (ROW - 1) / 2; }

bool upSide(int i) { return i == 0; }
bool downSide(int i, int ROW) { return i == ROW - 1; }
bool middleSide(int i, int ROW) { return i == midROW(ROW); }
bool upperMiddle(int i, int ROW) { return i > 0 && i < midROW(ROW); }
bool downMiddle(int i, int ROW) { return i > midROW(ROW) && i < ROW - 1; }

void printLCDUpperPart(char s) { cout << ((s == '1'|| s == '4') ? ' ' : '-'); }
void printLCDMiddlePart(char s) { cout << ((s == '0'|| s == '1' || s == '7') ? ' ' : '-'); }
void printLCDDownPart(char s) { cout << ((s == '1'|| s == '4' || s == '7') ? ' ' : '-'); }
void printLCDUpperRightBorderPart(char s) { cout << ((s == '5' || s == '6') ? ' ' : '|'); }
void printLCDDownRightBorderPart(char s) { cout << ((s == '2') ? ' ' : '|'); }
void printLCDUpperLeftBorderPart(char s) {
    cout << ((s == '1' || s == '2' || s == '3' || s == '7') ? ' ' : '|');
}

void printLCDDownLeftBorderPart(char s){
    cout << ((s == '1') || (s == '3') || (s == '4') || (s == '5') || (s == '7') || (s == '9') ? ' ' : '|');
}

int main() {
    int s = 0;
    std::string n;

    while(std::cin >> s >> n && s != 0)
    {
        if (!s) { return 0; }

        int ROW = rowOfNBasedOnS(s);
        int COLUMN = n.size();

        for(int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COLUMN; ++j)
            {
                // para los de arriba medio o abajo
                if ( upSide(i)) {
                    cout << " ";
                    for (int k = 0; k < s; k++) {
                        printLCDUpperPart(n[j]);
                    }
                    cout << " ";
                }

                if ( middleSide(i, ROW)) {
                    cout << " ";
                    for (int k = 0; k < s; k++) {
                        printLCDMiddlePart(n[j]);
                    }
                    cout << " ";
                }

                if ( downSide(i, ROW)) {
                    cout << " ";
                    for (int k = 0; k < s; k++) {
                        printLCDDownPart(n[j]);
                    }
                    cout << " ";
                }

                // para los de lateral arriba
                if (upperMiddle(i, ROW)) {
                    printLCDUpperLeftBorderPart(n[j]);
                    for (int k = 0; k < s; k++) {
                        cout << " ";
                    }
                    printLCDUpperRightBorderPart(n[j]);
                }

                // para los de lateral abajo
                if (downMiddle(i, ROW)) {
                    printLCDDownLeftBorderPart(n[j]);
                    for (int k = 0; k < s; k++) {
                        cout << " ";
                    }
                    printLCDDownRightBorderPart(n[j]);
                }

                // si no es el ultimo numero
                if (j != n.size()-1){ cout << " "; }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
