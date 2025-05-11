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
#define N 10005
#define MOD 1000000007
vector<int> Adj[N];


int in_degree[N] = {0};
void kahn(int n, int m) {
    priority_queue<int, vector<int>, greater<int> > q;
    vector<int> toposorting;

    for(int i=1;i<=n;i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int front = q.top();
        q.pop();
        toposorting.push_back(front);

        for(int child : Adj[front]) {

            in_degree[child]--;

            if(in_degree[child] == 0) {
               q.push(child);
            }
        }
    }

    if(toposorting.size() != n) {
        cout << "Sandro fails.";        
        return;
    }
    
    for(int it : toposorting) {
        cout << it << " ";
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

    int n,m; cin >> n >> m;
    vector<int> ordering;

    for(int i=0;i<m;i++) {
        
        int u,v; cin >> u >> v;
        Adj[u].push_back(v);
        in_degree[v]++;
    }
    
    kahn(n,m);

    return 0;
}