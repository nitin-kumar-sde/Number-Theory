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

vector<int> eulerPhi(N+1);

void buildPhi() {
    for(int i=0;i<=N;i++) {
        eulerPhi[i] = i;
    }

    for(int i=2; i <=N; i++) {

        if(eulerPhi[i] == i) {
            for(int j=i;j<=N;j+=i) 
            eulerPhi[j] = (eulerPhi[j]*(i-1))/i;
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

    buildPhi();

    for(int i=1;i<100;i++) {
        cout << eulerPhi[i] << endl;
    }

    return 0;
}