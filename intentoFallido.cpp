#include <bits/stdc++.h>
using namespace std;
/*
Input
The input file contains several lines, one for each number to be displayed. Each line
contains integers s and n, where n is the number to be displayed ( 0 <= n <= 99, 999, 999) and
s is the size in which it shall be displayed ( 1 <= s <= 10). The input will be terminated by a
line containing two zeros, which should not be processed.

Output
Print the numbers specified in the input file in an LCD display-style using s '-' signs
for the horizontal segments and s '|' signs for the vertical ones. Each digit occupies
exactly s + 2 columns and 2s + 3 rows. Be sure to fill all the white space occupied
by the digits with blanks, including the last digit. There must be exactly one column
of blanks between two digits.

Output a blank line after each number. You will find an example of each digit in the
sample output below.

Sample Input
2 12345
3 67890
0 0

Sample Output
      --   --        --
   |    |    | |  | |
   |    |    | |  | |
      --   --   --   --
   | |       |    |    |
   | |       |    |    |
      --   --        --

 ---   ---   ---   ---   ---
|         | |   | |   | |   |
|         | |   | |   | |   |
|         | |   | |   | |   |
 ---         ---   ---
|   |     | |   |     | |   |
|   |     | |   |     | |   |
|   |     | |   |     | |   |
 ---         ---   ---   ---
*/

int rowOfANumber(int s){ return 2*s + 3; }
int columnOfANumber(int s){ return s + 2; }
int midROW(int ROW){ return (ROW - 1) / 2; }

bool isInTheCorner(int i, int j, int ROW, int COL){
    return ((i == 0) && (j == 0)) || ((i == 0) && (j == COL - 1)) || ((i == ROW-1)
    && (j == 0)) || ( (i == (ROW - 1) ) && ( j == (COL-1) ) );
}
bool isInTheMiddleAndIsInTheEdges(int i, int j, int ROW, int COL){
    return ((i == midROW(ROW)) && (j == 0)) || ((i == midROW(ROW)) && (j == (COL - 1)) );
}
bool isInTheBorderAndBetweenUpAndMiddle(int i, int j, int ROW, int COL){
    int middle = midROW(ROW);
    return (i < middle && j == 0) || (i < middle && j == COL - 1);
}
bool isInTheBorderAndBetweenMiddleAndDown(int i, int j, int ROW, int COL){
    int middle = midROW(ROW);
    return (i > middle && i < ROW - 1 && j == 0) || (i > middle && i < ROW - 1 && j == COL - 1);
}
bool isBetweenUpAndMiddleInterior(int i, int j, int ROW, int COL){
    int middle = midROW(ROW);
    return (i < middle && i > 0) && (j > 0 && j < COL - 1) ;
}
bool isBetweenMiddleAndDownInterior(int i, int j, int ROW, int COL){
    int middle = midROW(ROW);
    return (i > middle && i < ROW - 1) && (j > 0 && j < COL - 1) ;
}

char **initMatrix(int ROW, int COL)
{
    char **mat = new char*[ROW];
    for (int i = 0; i < ROW; ++i) {
        mat[i] = new char[COL];
    }
    return mat;
}

char** buildEight(int s)
{
    const int COLUMN = columnOfANumber(s);
    const int ROW = rowOfANumber(s);
    char **m = initMatrix(ROW, COLUMN);
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            if ( isInTheCorner(i, j, ROW, COLUMN) || isInTheMiddleAndIsInTheEdges(i, j, ROW, COLUMN)
                 || isBetweenUpAndMiddleInterior(i, j, ROW, COLUMN) || isBetweenMiddleAndDownInterior(i, j, ROW, COLUMN)) {
                m[i][j] = ' ';
            }else {
                if (isInTheBorderAndBetweenUpAndMiddle(i, j, ROW, COLUMN) || isInTheBorderAndBetweenMiddleAndDown(i, j, ROW, COLUMN)){
                    m[i][j] = '|';
                }
                else{
                    m[i][j] = '-';
                }
            }
        }
    }
    return m;
}

//void printMatrixI(int ROW, int COLUMN)
//{
////    auto m = initMatrix(ROW, COLUMN);
//    for (int i = 0; i < ROW; ++i)
//    {
////        if(i == 0) { continue;}
//        for (int j = 0; j < COLUMN; ++j) {
//            cout << m[i][j];
//        } cout << endl;
//    }
//}

int main() {
    int s = 2;
    string n = "88";
//    int h[10][3];//horizontal line array size .here 9 means it may be 1,2,3,4,5,6,7,8,9 and 3 means here any number to made need maximum 3 horizontal line.
    auto ROW = rowOfANumber(s);
    auto COLUMN = columnOfANumber(s);
    std::vector<char**> matricesVec;

    for (int i = 0; i < static_cast<int>(n.size()); ++i) {
        switch(n[i]){
            case '0': {
                break;
            }
            case '1': {
                break;
            }
            case '2': {
                break;
            }
            case '3': {
                break;
            }
            case '4': {
                break;
            }
            case '5': {
                break;
            }
            case '6': {
                break;
            }
            case '7': {
                break;
            }
            case '8': {
                auto m8 = buildEight(s);
                matricesVec.push_back(m8);
                for (int j = 0; j < ROW; ++j)
                {
                    for (int k = 0; k < COLUMN; ++k) {
                        cout << m8[j][k];
                    }
                    if (j == ROW-1) {

                    }else {
                        cout << endl;
                    }
                }

                break;
            }
            case '9': {
                break;
            }
            default:break;
        }
    }




//    for (int i = 0; i < ROW; ++i)
//    {
//        for (int j = 0; j < COLUMN; ++j) {
//            cout << m[i][j];
//        } cout << endl;
//    } cout << endl;

//    h[0][0]=h[0][2]=1;//horizontal line for 0;
//    h[0][1]=0;
//    h[1][0]=h[1][1]=h[1][2]=0;//horizontal line for 1;
//    h[2][0]=h[2][1]=h[2][2]=1;  //horizontal line for 2;
//    h[3][0]=h[3][1]=h[3][2]=1; //horizontal line for 3;
//    h[4][1]=1;
//    h[4][0]=h[4][2]=0; //horizontal line for 4;
//    h[5][0]=h[5][1]=h[5][2]=1;//horizontal line for 5;
//    h[6][0]=h[6][1]=h[6][2]=1; //horizontal line for 6;
//    h[7][0]=1;//horizontal line for 7;
//    h[7][1]=h[7][2]=0;
//    h[8][0]=h[8][1]=h[8][2]=1;//horizontal line for 8;
//    h[9][0]=h[9][1]=h[9][2]=1;//horizontal line for 9;
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            cout << h[i][j] << " ";
//        } cout << endl;
//    } cout << endl;
//    int v[10][4];//vertical line array size.Here 9 means digit can be 1,2,3,4,5,6,7,8,9 and 3 means vertical line can be maximum 4 for any digit representation;
//    for (int k = 0; k < 10; ++k) {
//        for (int i = 0; i < 4; ++i) {
//            v[k][i] = 0;
//        }
//    }
//    v[0][1]=v[0][3]=v[0][0]=v[0][2]=1;//vertical line for digit 0;
//    v[1][1]=v[1][3]=1;//vertical line for digit 1;
//    v[1][0]=v[1][2]=0;
//    v[2][1]=v[2][2]=1;//vertical line representation for digit 2;
//    v[2][0]=v[2][3]=0;
//    v[3][1]=v[3][3]=1;//vertical line representation for digit 3;
//    v[3][0]=v[3][2]=0;
//    v[4][0]=v[4][1]=v[4][3]=1;//vertical line representation for digit 4;
//    v[4][2]=0;
//    v[5][0]=v[5][3]=1;//vertical line representation for digit 5;
//    v[5][1]=v[5][2]=0;
//    v[6][0]=v[6][2]=v[6][3]=1;//vertical line representation for digit 6;
//    v[6][1]=0;
//    v[7][1]=v[7][3]=1;//vertical line representation for digit 7;
//    v[7][0]=v[7][2]=0;
//    v[8][0]=v[8][1]=v[8][2]=v[8][3]=1;//vertical line representation for digit 8;
//    v[9][0]=v[9][1]=v[9][3]=1;//vertical line representation for digit 9;
//    v[9][2]=0;
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            cout << v[i][j] << " ";
//        } cout << endl;
//    }
//    int s = 0; std::string numStr;
//    while (cin >> s >> numStr && s != 0)
//    {
//        auto res = spaceOfANumber(s);
//        for (int r = 0; r < rowOfANumber(s); ++r)
//        {
//            for (int c = 0; c < columnOfANumber(s); ++c) {
//                cout << res[r][c];
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    return 0;
}





//char** spaceOfANumber(int s) {
//    int row = rowOfANumber(s);
//    int column = columnOfANumber(s);
//    char** matrixSpace = nullptr;
//    matrixSpace = new char*[row];
//    for (int r = 0; r < row; ++r)
//    {
//        matrixSpace[r] = new char[column];
//        for (int c = 0; c < column; ++c) {
//            if (r % 3 == 0) matrixSpace[r][c] = ' ';
//            else {
//                if (r % 3 != 0 && c % 3 != 0) {
//                    matrixSpace[r][c] = ' ';
//                } else{
//                    if (c == 0) matrixSpace[r][c] = ' ';
//                    else matrixSpace[r][c] = '|';
//                }
//            }
//        }
//    }
//    return matrixSpace;
//}
