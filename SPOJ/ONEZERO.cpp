#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
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
string bfs(ll n) {
    string one = "1";
    ll remainder = 1%n;
    if(remainder == 0) return "1";

    queue<pair<string, ll>> q;
    q.push({one, remainder});

    while(!q.empty()) {
        pair<string, ll> front = q.front();
        q.pop();

        string num  = front.first;
        string num1 = num + "0";
        string num2 = num + "1";

        ll rem = front.second;
        ll rem1 = ((10%n)*(front.second%n))%n;
        ll rem2 = (((10%n)*(front.second)%n)%n + 1%n)%n;

        if(!rem1){
            return num1;
        }

        if(!rem2){
            return num2;
        }
        q.push({num1, rem1});
        q.push({num2, rem2});
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

    int t; cin >> t; 

    while(t--) {
        ll n; cin >> n;
        string ans = bfs(n);
        cout << ans << endl;
    }

    return 0;
}