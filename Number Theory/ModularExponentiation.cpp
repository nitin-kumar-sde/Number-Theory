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
ll modularExponentiation(ll a, ll b) {
    if(b==0) return 1;

    ll ans = modularExponentiation((a*a)%MOD, b/2);
    if(b%2) 
    ans = (ans * a%MOD)%MOD;
    
    return ans;
}

ll modularExponentiationIterative(ll a, ll b) {
    ll result = 1;
    while(b>0) {
        if(b%2)
        result  = (result * (a %MOD)) %MOD;
        b/=2;
        a = (a*a)%MOD;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    ll a, b; cin >> a >> b;

    ll ans = modularExponentiationIterative(a, b);

    cout << ans << endl;

    return 0;
}