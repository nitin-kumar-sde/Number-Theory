#include<iostream>
using namespace std;

const int N = 15;
int board[N][N] = {0};

// check if it is safe to place given queen
bool isSafe(int row, int col, int n) {
    
    // column check
    for(int i=row-1;i>=0;i--) {
      if(board[i][col]) return false;
    }
    
    // diagonal up- left check 
    int i=row-1, j = col-1;
    while(i >=0 && j >=0) {
      if(board[i][j]) return false;
      i--; j--;
    }
  
    // diagonal up-right check
    i = row-1, j = col+1;
    while(i>=0 && j<n) {
       if(board[i][j]) return false;
       i--; j++;
    }

    return true;
}
  
void printSolution(int n) {

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          cout << board[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;  
}
void placeNQueensHelper(int row, int n) {
    // print valid solution
    if(row == n) {
      printSolution(n);
      return;
    }
  
    for(int i=0;i<n;i++) {
        if(isSafe(row, i , n)) {
        board[row][i] = 1;
        placeNQueensHelper(row+1, n);
        board[row][i] = 0;
        }
    }
}
  
int main() {

    int n = 5;
    placeNQueensHelper(0, n);
    return 0;
}
  
