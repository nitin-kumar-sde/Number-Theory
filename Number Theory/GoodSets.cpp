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

vector<int> goodSets(N+1, 0);
void buildGoodSets() {
    
    for(int i=1; i <=N; i++) {

        if(goodSets[i] != 0) {
            for(int j=2*i;j<=N;j+=i) {
                if(goodSets[j] == 0) continue;
                goodSets[j] = (goodSets[j] + goodSets[i])%MOD;
            }
            
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

    int t; cin >> t;

    while(t--) {

        ll n ; cin >> n;
        for(int i=0;i<=N;i++) {
            goodSets[i] = 0;
        }

        for(int i=0;i<n;i++) {
            ll temp;  cin >> temp;
            goodSets[temp] ++;
        }

        buildGoodSets();
        ll count = 0;

        for(int i=0;i<=N;i++) {
            count = (count + goodSets[i])%MOD;
            // cout << goodSets[i] << endl;
        }

        cout << count << endl;

    }
    return 0;
}