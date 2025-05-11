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

vector<int> Adj[N];

int diameter[N+1]  = {0};

int dfs(int src, int par) {    
    int fmax = 0, smax = 0;
    
    int children = 0;
    int k = 0;
    for(auto it : Adj[src]) {
        if(it == par) continue;
        
        children++;
        int depth = dfs(it, src);
        k = max(k, diameter[it]);
        if(depth > fmax) {
            smax = fmax;
            fmax = depth;
        }
        else {
            smax = max(smax, depth);
        }
    }
    int ans = 0;

    if(children == 1) ans = max(k, 1 + fmax);

    if(children >= 2) ans = max(k, 2 + fmax + smax);

    diameter[src] = ans;
    if(children == 0 ) return fmax;
    
    return 1 + fmax;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    for(int i=0;i<n-1;i++) {
        int u, v; 
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    
    int root; cin >> root;

    dfs(root, -1);
    // dfs2(root, -1);

    int q; cin >> q;

    for(int i=0;i<q;i++) {
        int query; cin >> query;

        cout << diameter[query] << endl;
    }

    return 0;
}