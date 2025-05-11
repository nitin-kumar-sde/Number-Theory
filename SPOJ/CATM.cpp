#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 105
#define MOD 1000000007
int MAZE[N][N];

int drow[] = {-1, 1, 0, 0};  
int dcol[] = {0, 0, -1, 1}; 

void initialise(int n, int m) {
    for(int i=0;i<=n;i++) {
       for(int j=0;j<=m;j++)
        MAZE[i][j] = 0;
    }
}

bool bfs(int n, int m , pair<int, int> mouse, pair<int, int> cat1, 
pair<int,int> cat2) {

    // mouse on same as cat1 - no chance
    if(mouse.first == cat1.first && mouse.second == cat1.second)
    return false;

    // mouse on same as cat2 - no chance
    if(mouse.first == cat2.first && mouse.second == cat2.second)
    return false;
     
    // run BFS to check for the non-boarder cases
    MAZE[mouse.first][mouse.second] = 1;
    MAZE[cat1.first][cat1.second] = 1;
    MAZE[cat2.first][cat2.second] = 1;
    
    queue<pair<pair<int,int>, char> > q;
    
    q.push({cat1, 'c'});
    q.push({cat2, 'c'});
    q.push({mouse, 'm'});
    
    while(!q.empty()) {
        
        pair<pair<int,int>, char> front = q.front();
        q.pop();
        // mouse reached boarder
        if((front.first.first == 1 || front.first.first == n || 
            front.first.second == 1 || front.first.second == m) 
               && front.second == 'm')
        return true;

        // traverse all 4 directions - horizontally / vertically
        for(int i=0;i<4;i++) {
            int new_x = front.first.first + drow[i];
            int new_y = front.first.second + dcol[i];
            
            if(new_x >=1 && new_x <=n && new_y >=1 && new_y <= m && 
            MAZE[new_x][new_y] == 0)
            { 

              q.push({{new_x, new_y}, front.second});
              MAZE[new_x][new_y] = 1;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n >> m;

    int k; cin >> k;

    while(k--) {
        
        initialise(n,m);

        int mouse_x, mouse_y; 
        cin >> mouse_x >> mouse_y;

        int cat1_x, cat1_y; 
        cin >> cat1_x >> cat1_y;

        int cat2_x, cat2_y; 
        cin >> cat2_x >> cat2_y;

        bool isPossible = bfs(n, m , {mouse_x, mouse_y}, 
        {cat1_x, cat1_y}, {cat2_x, cat2_y});

        if(isPossible) {
            cout << "YES" << endl;
        }
        else 
        cout << "NO" << endl;

    }


    return 0;
}