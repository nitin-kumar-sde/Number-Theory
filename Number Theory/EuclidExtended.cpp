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

class Triplet {
  public :
    ll x;
    ll y;
    ll gcd;
};

Triplet extendedEuclid(int a, int b) {

    // if(b>a) return extendedEuclid(b, a);

    if(b==0) {
        Triplet t; 
        t.gcd = a;
        t.x = 1;
        t.y = 0;
        return t;
    }

    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans ;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - ((a/b)* smallAns.y);
    return ans;
}

ll getModuloMultiplicativeInverse(ll a, ll b) {
    Triplet t  = extendedEuclid(a, b);
    ll ans = ((t.x)%b + b)%b;
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

    ll a, b;
    cin >> a >> b;

    ll modMultInverse = getModuloMultiplicativeInverse(a, b);

    cout << modMultInverse;
    return 0;
}