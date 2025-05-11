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

int longestNonRepeatingSubstring(string& s){
    int i=0;
    int j=0;
    int n = s.length();
    int lastIndex[256];  
    for(int k = 0; k < 256; k++) 
    lastIndex[k] = -1;

    int ans = 0;
    int start = 0;
    int end = 0;

    while(j<n) {
        if(lastIndex[s[j]] >= i) {
            i = lastIndex[s[j]] + 1;
        }
        lastIndex[s[j]] = j;
        // ans = max(ans, j-i+1);
        if((j-i+1) > ans) {
            ans = j-i+1;
            start = i;
            end = j;
        }
        j++;
    }
    // for(int k = 0; k < 256; k++) 
    // {
    //     if(lastIndex[k] != -1) cout << lastIndex[k] << endl;
    // }
    cout << start << " " << end << " " << endl;
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

    string s; cin >> s;

    int maxlength = longestNonRepeatingSubstring(s);

    cout << maxlength << endl;

    return 0;
}