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
#define N 10000005
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

    int n; cin >> n;

    ll count = 0;

    for(int i=1;i<=n;i++) {
        if(isPrime[i]) count++;
    }
    
    cout << count;

    return 0;
}