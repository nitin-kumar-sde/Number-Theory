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
#define N 5000005
#define MOD 1000000007

vector<int> lowestPrimeDivisor(N+1, 1);

void buildSieve() {
    
    for(int i=2; i<=N; i++) {

        if(lowestPrimeDivisor[i] == 1) {
            for(int j=i;j<=N;j+=i) 
            if(lowestPrimeDivisor[j] == 1)
            lowestPrimeDivisor[j] = i;
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

    ll n; cin >> n;

    ll * marked = new ll [n+1];
    for(int i=1;i<=n;i++) marked[i] = false;
    vector<ll> strangeOrder;
    vector<ll> strangeOrderFinal;

    for(int i=n;i>0;i--) {
        if(marked[i]) continue;
        strangeOrder = {};
        int currentElemenet = i;
        int x = lowestPrimeDivisor[currentElemenet];
        while(x>1) {
            int current = i;
            while(current >=1) {
                if(!marked[current])
                strangeOrder.push_back(current);
                marked[current] = true;
                current-=x;
            }
            while(currentElemenet%x == 0) 
            currentElemenet/=x;
            x= lowestPrimeDivisor[currentElemenet];
        }
       
        sort(strangeOrder.begin(), strangeOrder.end(), greater<int>());
        strangeOrderFinal.insert(strangeOrderFinal.end(), 
        strangeOrder.begin(), strangeOrder.end());
    }
    

    strangeOrderFinal.push_back(1);
    // auto last = unique(strangeOrderFinal.begin(), strangeOrderFinal.end());
    // strangeOrderFinal.erase(last, strangeOrderFinal.end());

    for(int i=0;i<strangeOrderFinal.size();i++) 
    cout << strangeOrderFinal[i] << " ";
    return 0;
}