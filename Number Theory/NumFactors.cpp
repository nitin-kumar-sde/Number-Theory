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

vector<int> factorCount(N+1, 0);

void buildSieve() {
    
    for(int i=2; i <=N; i++) {

        if(factorCount[i] == 0) {
            factorCount[i] = 1;
            for(int j=2*i;j<=N;j+=i) 
            factorCount[j]++;
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

    buildSieve();

    ll ** numFactor = new ll * [11];

    for(int i=0;i<=10;i++) {
        numFactor[i] = new ll [N+1];
        for(int j=0;j<=N;j++) numFactor[i][j] = 0;
    }

    for(int i=1; i<=N; i++) {
        for(int j=0;j<11;j++) 
        numFactor[j][i] = numFactor[j][i-1];
        int k = factorCount[i];
        if(k<=10) numFactor[k][i]++;
    }

    int t; cin >> t;

    while(t--) {
        ll a, b, n; cin >> a >> b >> n;

        ll count = numFactor[n][b] - numFactor[n][a-1];

        cout << count << endl;
    }
   
    return 0;
}