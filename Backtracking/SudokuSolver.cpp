#include<iostream>
using namespace std;
const int N = 15;

pair<int, int> getNextShell(int x, int y) {
    y = y+1;
 
    if(y ==9) {
        x = x+1;
        y = 0;
    }
    return {x, y};
}
// check if num can be placed on x,y
bool isValid(int board[][9], int x, int y, int num) {
    // row check
     for(int i=0;i<9;i++)  {
        if(board[i][y] == num) return false;
     }
     // col check
     for(int i=0;i<9;i++) {
         if(board[x][i] == num) return false;
     }
     // chech in 3*3 matrix
     int i = x/3; int j = y/3;
 
     for(int k=3*i;k<=3*i+2;k++) {
         for(int l = 3*j; l<=3*j+2;l++) {
            if(board[k][l] == num) return false;
         }
     }
     
     return true;
 }

bool sudokuSolver(int board[][9], int x, int y) {
     // base case
     if(x == 9) return true;
 
     pair<int, int> next = getNextShell(x, y);
     
     int xNext = next.first;
     int yNext = next.second;
 
     if(board[x][y]) return sudokuSolver(board, xNext, yNext);
 
     for(int i=1;i<=9;i++) {
         if(isValid(board, x, y, i)) {
         board[x][y] = i;
         if(sudokuSolver(board, xNext, yNext)) return true;
         }
     }
     board[x][y] = 0;
 
     return false;
 
 
}

int main() {
    int sudoku[9][9] = {
        {9, 0, 0, 0, 2, 0, 7, 5, 0 },
        {6, 0, 0, 0, 5, 0, 0, 4, 0 }, 
        {0, 2, 0, 4, 0, 0, 0, 1, 0 },
        {2, 0, 8, 0, 0, 0, 0, 0, 0 }, 
        {0, 7, 0, 5, 0, 9, 0, 6, 0 }, 
        {0, 0, 0, 0, 0, 0, 4, 0, 1 }, 
        {0, 1, 0, 0, 0, 5, 0, 8, 0 }, 
        {0, 9, 0, 0, 7, 0, 0, 0, 4 }, 
        {0, 8, 2, 0, 4, 0, 0, 0, 6 }};

    cout << sudokuSolver(sudoku, 0,0);
}

 
