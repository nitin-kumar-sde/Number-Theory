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
vector<bool> isCubeFree(N+1, true);
map<int,int> rankMap;

void buildSieve() {
    
    for(int i=2; i <=100; i++) {
        int cube = i*i*i;
        for(int j=cube; j<=N; j+=cube)
        isCubeFree[j] = false;
    }

    int rank = 1;

    for(int i=1;i<=N;i++) {

        if(isCubeFree[i]) 
        rankMap[i] = rank++;
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
    int t; cin >> t;

    for(int i=1;i<=t; i++) {

      int n; cin >> n;

      if((rankMap.count(n)) != 0) {
        cout << "Case " << i << ":" << rankMap[n] << endl;
      }
      else {
        cout << "Case " << i << ":" << "Not Cube Free" << endl;
      }
    }

    return 0;
}