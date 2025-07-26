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
#define N 2000005
#define MOD 1000000007

vector<int> lowestPrimeDivisor(N+1, 1);
int marked [N]= {0};

// builds lowest prime divisor of a number
void buildSieve() {
    
    for(int i=2; i<=N; i++) {

        if(lowestPrimeDivisor[i] == 1) {
            for(int j=i;j<=N;j+=i) 
            if(lowestPrimeDivisor[j] == 1)
            lowestPrimeDivisor[j] = i;
        }
    }

}

// prime factorisation based on the lpd
vector<int> getPrimeDivisor(int num) {
    vector<int> primes;
    int x = lowestPrimeDivisor[num];

    while(x>1) {
        primes.push_back(x);
        while(num%x == 0) num/=x;
        x= lowestPrimeDivisor[num];
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    buildSieve();

    ll n; cin >> n;

    
    for(int i=1;i<=n;i++) marked[i] = false;
    vector<ll> strangeOrderFinal;

    for(int i=n;i>0;i--) {
        if(marked[i]) continue;
        vector<ll> strangeOrder;
        int currentElemenet = i;
        vector<int> divisors = getPrimeDivisor(currentElemenet);

        for(int pd : divisors) {
            currentElemenet = i;
            while(currentElemenet >=1) {
                if(!marked[currentElemenet]) {
                strangeOrder.push_back(currentElemenet);
                marked[currentElemenet] = true;
                }
                currentElemenet-=pd;
            }
        }
       
        sort(strangeOrder.begin(), strangeOrder.end(), greater<int>());
        strangeOrderFinal.insert(strangeOrderFinal.end(), 
        strangeOrder.begin(), strangeOrder.end());
    }
    

    strangeOrderFinal.push_back(1);

    for(int i=0;i<strangeOrderFinal.size();i++) 
    cout << strangeOrderFinal[i] << " ";
    return 0;
}
