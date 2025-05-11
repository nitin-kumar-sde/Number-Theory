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
#define N 50000
#define MOD 1000000007

vector<bool> isPrime(N+1, true);

void buildSieve() {
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i*i <=N; i++) {

        if(isPrime[i]) {
            for(int j=i*i;j<=N;j+=i) 
            isPrime[j] = false;
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

    int t; cin >> t;

    while(t--) {

        ll n; cin >> n;

        ll ans = 1;

        for(int i=2;i<=n;i++) {

            if(!isPrime[i]) continue;

            ll count = 1;
            ll temp = n;

            while(temp/i) {
                count = count + ((temp/i)%MOD);
                count = count % MOD;
                temp/=i;
            }

            ans = (ans * count)% MOD;
        }
        cout << ans << endl;
    }

    return 0;
}