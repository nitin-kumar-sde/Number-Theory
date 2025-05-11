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
#define N 2000005
#define MOD 1000000007
int cats[N+1] = {0};
int visited[N+1] = {0};
vector<int> Adj[N+1];

int dfs(int src , int m, int n) {
    if(n < 0) return 0;
    
    visited[src] = 1;
    int ans = 0;
    bool leaf = true;
    for(int it : Adj[src]) {
        if(!visited[it]) {
            ans += dfs(it, m, (cats[src] == 1)? n-1: m);
            leaf = false;
        }
    }
    
    if(leaf && (n > 0 || (n == 0 && cats[src] == 0)))
    ans++;
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

    int n,m; cin >> n >> m;

    
    for(int i=1;i<=n;i++) cin >> cats[i];

    
    for(int i=0;i<n-1;i++) {
        int u,v; cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    
    int ans = dfs(1, m, m);
    cout << ans << endl;
    return 0;
}