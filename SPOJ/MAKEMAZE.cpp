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
         && grid[row][col] == '.');
}


int dfs(string * grid, int n ,int m , 
    int ** visited, int row, int col, int targetx, int targety) {
    
    visited[row][col] = 1;

    if(row == targetx && col == targety)
    return true;

    bool  ans = false;
    for(int i=0;i<4;i++) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if(isValid(grid, n, m, visited, new_row, new_col)) 
        {
            ans = ans || dfs(grid, n, m, visited, 
                new_row, new_col, targetx, targety);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    int t; cin >> t; 

    while(t--) {

    int n,m; cin >> n >> m;

    string * grid = new string [n];
    for(int i=0;i<n;i++) cin >> grid[i];
    int** visited  = new int* [n];

    for(int i=0;i<n;i++) {
        visited[i] = new int[m];
        for(int j=0;j<m;j++)
        { 
            visited[i][j] = 0;
        }
    }
    vector<pair<int, int>> openings;

    for(int i=0;i<n;i++) {
        if(grid[i][0] == '.') {
            openings.push_back({i, 0});
        }
        if(grid[i][m-1] == '.') {
            openings.push_back({i, m-1});
        }
    }

    for(int i=1;i<m-1;i++) {
        if(grid[0][i] == '.') {
            openings.push_back({0, i});
        }
        if(grid[n-1][i] == '.') {
            openings.push_back({n-1, i});
        }
    }


    sort(openings.begin(), openings.end()); 
    openings.erase(unique(openings.begin(), 
    openings.end()), openings.end()); 
    
    // cout << openings.size() << " haha " << endl;

    if(openings.size() != 2) {
        cout << "invalid" << endl;
        continue;
    }
    bool ans = dfs(grid, n, m, visited, openings[0].first, 
        openings[0].second, openings[1].first, 
        openings[1].second);
    
    if(ans)
    cout << "valid" << endl;
    else
    cout << "invalid" << endl;
    
}

    return 0;
}