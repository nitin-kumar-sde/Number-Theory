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

vector<bool> isPrime(N+1, true);

int visited [N] = {0};
int dist [N] = {0};

void initialise() {

    for(int i=0;i<N;i++) 
    dist[i] = 1e9;

}
void buildSieve() {
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i*i <=N; i++) {

        if(isPrime[i]) {
            for(int j=i*i;j<=N;j+=i) 
            isPrime[j] = false;
        }
    }

}
vector<int> Adj[N+1];


void dijkstra(int n) {
   
    set<pair<int,int> > s;
    for(int i=0;i<=n;i++) {
        if(isPrime[i]) {
            s.insert({0, i});
            dist[i] = 0;
        }
    }

    while(!s.empty()) {
        auto it = *s.begin();
        s.erase(s.begin());

        int dis = it.first;
        int node = it.second;

        if(visited[node]) continue;

        visited[node] = 1;

        for(auto it : Adj[node]) {
            if( dist[it] > max(it, node) + dist[node] ) {
                dist[it] = max(it, node) + dist[node];
                s.insert({dist[it], it});
            } 
        }

    }

    for(int i=1;i<=n;i++) {
        int ans = (dist[i] == 1e9) ? -1 : dist[i];
        cout << ans << " "; 
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

    buildSieve();
    initialise();
    int n,m;

    cin >> n >> m;

    for(int i=0;i<m;i++) {
        int u,v; 
        cin >> u >> v;

        // for undirected graphs
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    dijkstra(n);
    return 0;
}