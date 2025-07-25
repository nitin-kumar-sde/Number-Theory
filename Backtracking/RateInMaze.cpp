#include<iostream>
using namespace std;
const int N = 15;
int maze[N][N] = {{1,0,1}, {1,0,1}, {1,1,1}};
int solution[N][N] = {0};

int delta_row [] = {1, 0, 0, -1};
int delta_col [] = {0, 1, -1, 0};

void print(int n) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) 
      cout << solution[i][j] << " ";
    }
    cout << endl;
}

bool isValid(int start, int end, int n) {
    return (start >= 0 && start < n && end >= 0 && end < n 
        && !solution[start][end] && maze[start][end]);
}
void ratInAMazeHelper(int row, int col, int n) {
    
    // reached end of maze
    if(row == n-1 && col == n-1) {
      solution[row][col] = 1;
      print(n);
      solution[row][col] = 0;
      return;
    }
    solution[row][col] = 1;
    for(int i=0;i<4;i++) {
        int new_row = row + delta_row[i];
        int new_col = col + delta_col[i];

        if(!isValid(new_row, new_col, n)) continue;
       
        ratInAMazeHelper(new_row, new_col, n);
        
    }
    solution[row][col] = 0;

}

int main() {

    int n = 3;
    ratInAMazeHelper(0,0,3);
}
 
