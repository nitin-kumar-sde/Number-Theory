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

ll gcd(ll a, ll b) {

    if(a <b) return gcd(b, a);

    if(b == 0) return a;

    return gcd(b, a%b);
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

        ll a; string b;

        cin >> a >> b;

        if(a ==0) {
            cout << b << endl;
            continue;
        }

        ll remainder = 0;
        ll powerMult = 1;

        for(int i=0;i<b.size(); i++) {

            int digit = b[b.size()-i-1] - '0';
            ll product = ((digit % a) * powerMult)%a;
            powerMult = (powerMult* (10%a))%a;
            remainder += product;
            remainder = remainder%a;
        }
        
        ll ans = gcd(remainder, a);

        cout << ans << endl;
    }

    return 0;
}