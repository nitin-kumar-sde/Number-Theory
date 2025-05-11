#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007
int drow[] = {-1, 1, 0, 0};  
int dcol[] = {0, 0, -1, 1}; 

bool isValid(string * grid, int n, int m, int ** visited, 
    int row, int col) {
    
        return (row >=0 && row <n && col >=0 && col < m && visited[row][col] == 0
         && grid[row][col] != '#');
}

pair<int,int> dfs2(string * grid, int n, int m, int ** visited, 
    int row, int col) {

    if(grid[row][col] == '#') 
    return {0,0};

    visited[row][col] = 1;
    int sheep = grid[row][col] == 'k', wolf = grid[row][col] == 'v';
    
    for(int i=0;i<4;i++) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if(isValid(grid, n, m, visited, new_row, new_col)) 
        {
            pair<int, int> ans = dfs2(grid, n, m, visited, new_row, new_col);
            sheep+= ans.first;
            wolf+=ans.second;
        }
    }
    return {sheep, wolf};
}
void dfs(string * grid, int n, int m, int ** visited, 
    int row, int col) {
    
    visited[row][col] = 1;

    for(int i=0;i<4;i++) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if(isValid(grid, n, m, visited, new_row, new_col)) 
        {
            dfs(grid, n, m, visited, new_row, new_col);
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    int n, m; cin >> n >> m;

    string * grid = new string [n];

    for(int i=0;i<n;i++) cin >> grid[i];

    int** visited  = new int* [n];
    int total_sheep = 0, total_wolf = 0;
    for(int i=0;i<n;i++) {
        visited[i] = new int[m];
        for(int j=0;j<m;j++)
        { 
            visited[i][j] = 0;
            total_sheep +=(grid[i][j] == 'k');
            total_wolf +=(grid[i][j] == 'v');
        }
    }
    int sheep_died = 0, wolf_died = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if((i==0 || i== n-1 || j == 0 || j == m-1 ) 
            && visited[i][j] == 0 && grid[i][j] != '#')
            dfs(grid, n, m , visited, i, j);
        }
    }
    
    for(int i=1;i<n-1;i++) {

        for(int j=1;j<m-1;j++) {
           if(visited[i][j] == 0) {
            pair<int, int> ans = dfs2(grid, n, m , visited, i, j);
            
            if(ans.first > ans.second)
            wolf_died += (ans.second);
            else if(ans.first <= ans.second) 
            sheep_died += (ans.first);

           }
        }
    }

    int sheep_sur = total_sheep - sheep_died;
    int wolf_sur = total_wolf - wolf_died;

    cout << sheep_sur << " " << wolf_sur << endl;

    return 0;
}