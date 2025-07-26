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

// recursive modular exponentiation
ll modularExponentiation(ll a, ll b, ll c) {
    if(b==0) return 1;

    ll ans = modularExponentiation((a*a)%c, b/2, c);
    if(b%2) 
    ans = (ans * a%c)%c;
    
    return ans;
}

// iterative modular exponentiation
ll modularExponentiationIterative(ll a, ll b, ll c) {
    ll result = 1;
    while(b>0) {
        if(b%2)
        result  = (result * (a %c)) %c;
        b/=2;
        a = (a*a)%c;
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

    ll ans = modularExponentiationIterative(a, b, MOD);

    cout << ans << endl;

    return 0;
}
