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
vector<bool> isPrime(N+1, true);

void buildSieve(ll l, ll r, vector<int> primes) {
    for(int i=l; i <=N; i++) 
    isPrime[i] = true;
    
    for(int i=0; primes[i] * primes[i] <=r; i++) {
        int startIndex = (ceil((1.0* l)/primes[i]) ) * primes[i];
        for(int j=max(primes[i]*primes[i],startIndex) ;j<=r;j+=primes[i]) 
        isPrime[j-l] = false;   
    }

}

vector<int> sieveOfEratosthenes() {
    vector<bool> sieve(N + 1, true);
    vector<int> primes;

    sieve[0] = sieve[1] = false; 

    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i)
            sieve[j] = false;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (sieve[i])
            primes.push_back(i);
    }

    return primes;
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
    vector<int> primes  = sieveOfEratosthenes();

    while(t--) {
    ll l, r; cin >> l >> r;
    buildSieve(l, r, primes);

    for(int i=l;i<=r;i++) {
        if(isPrime[i-l]) cout << i << endl;
    }

    }
    return 0;
}