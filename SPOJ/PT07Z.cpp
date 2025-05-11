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
#define N 10005
#define MOD 1000000007
vector<int> Adj[N];

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
    
    int diameter = findDiametet()

    return 0;
}