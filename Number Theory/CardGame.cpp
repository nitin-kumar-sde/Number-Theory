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

ll getFirstValidEndIndex(ll * prefixProduct, ll start, ll n, ll k) {

    ll ans = n; ll low = start; ll high = n-1;

    while(low <= high) {
        ll mid = (low + high)/2;

        ll targetProduct = prefixProduct[mid];
        
        if(prefixProduct[start-1] == 0) 
        return n-1;
        if(start !=0) {
            targetProduct/= prefixProduct[start-1];
        }

        if(targetProduct%k == 0) {
            ans = mid;
            high = mid-1;
        }
        else low = mid + 1;
        
    }
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

    ll n, k; cin >> n >> k;

    ll * input = new ll [n]; 

    for(int i=0;i<n;i++) cin >> input[i];

    ll * prefixProduct = new ll [n];

    prefixProduct[0] = input[0];
    for(int i=1; i<n; i++) 
    prefixProduct[i] = prefixProduct[i-1] * input[i];

    ll count = 0;
    
    for(ll i=0;i<n;i++) {

        ll index = getFirstValidEndIndex(prefixProduct, i, n, k);
        if(index == n) continue;
        count = count + (n-index);
        // cout << i << " " << prefixProduct[i]<< " " << index << endl;
    }

    cout << count << endl;

    return 0;
}