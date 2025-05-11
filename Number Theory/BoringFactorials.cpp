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
// #define MOD 1000000007
ll modularExponentiation(ll a, ll b, ll mod) {
    if(b==0) return 1;

    ll ans = modularExponentiation((a*a)%mod, b/2, mod);
    if(b%2) 
    ans = (ans * a%mod)%mod;
    
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
    int t; cin >> t;

    while(t--) {
        ll n, p; cin >> n >> p;
        if(n>=p) {
            cout << "0" << endl;
            continue;
        }

        ll result = p-1;
        for(int i=n+1;i<p;i++) {
            result = (result * modularExponentiation(i, p-2, p))%p;
        }
        cout << result << endl;
    }

    return 0;
}