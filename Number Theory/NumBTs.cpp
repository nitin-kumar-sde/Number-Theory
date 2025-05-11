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
ll numBinaryTrees(ll n) {
    if(n==0 || n == 1) return 1;

    ll ans1 = numBinaryTrees(n-1);

    ll ans2 = numBinaryTrees(n-2);

    ll ans = (2* ((ans1*ans2)%MOD) + (ans1*ans1)%MOD)%MOD;

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

    ll n; cin >> n;

    ll ans = numBinaryTrees(n);

    cout << ans << endl;

    return 0;
}