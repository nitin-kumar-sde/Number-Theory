#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <numeric> 

using namespace std;

#define ll long long

#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007


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

        int n,k; 
        cin >> n >> k;
        string input; 
        cin >> input;

        int count = 0;
        
        for(int i=0;i<k;i++)
        {
            count +=(input[i] =='B');
        }
        int ans = count;
        int i=0, j=k;

        while(j<n) {
            count +=(input[j] =='B');
            count -=(input[i] =='B');
            i++; j++;
            ans = max(ans, count);
        }
        cout << k - ans << endl;
    } 

    return 0;
}