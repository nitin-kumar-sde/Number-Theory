#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include<queue>
#include <fstream>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

vector<bool> isPrime(N+1, true);
int pw[4] = {1000, 100, 10, 1}; 

void buildSieve() {
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i*i <=N; i++) {

        if(isPrime[i]) {
            for(int j=i*i;j<=N;j+=i) 
            isPrime[j] = false;
        }
    }

}

bool isValid(int num, map<int, int> &vist) {
    
    if(vist.count(num)>0) return false;

    if(!isPrime[num]) return false;

    return true;

}
int getNum(int num, int place, int digit) {
    if(place == 1 && digit == 0) return num;
    
    int temp = num;
    for(int i=0;i < 4-place;i++) temp = temp/10;
    int curr = temp%10;

    num = num - pw[place-1] * curr;
    num = num + pw[place-1] * digit;

    return num;
}
int bfs(int num1, int num2) {

    queue<pair<int, int>> q; 
    q.push({num1, 0});
    map<int, int> vist;
    vist[num1] = 0;

    while(!q.empty()){
         pair<int, int> p = q.front();
         q.pop();

         for(int i=1;i<=4;i++) {

           for(int j=0;j<=9;j++) {
            
            int num = getNum(p.first, i, j);

            if(num == num2) return 1 + p.second;

            // check for validity 
            if(isValid(num, vist)) {
                q.push({num, 1 + p.second});
                vist[num] = 1 + p.second;
            }
         }
       }
    }
    return -1;
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
    int t; cin >> t;
    
    while(t--) {
        int num1 , num2; 
        cin >> num1 >> num2;
        if(num1 == num2)
        {
            cout << "0" << endl;
            continue;
        }
        int ans = bfs(num1, num2);

        if(ans == -1) 
        cout << "Impossible" << endl;
        else 
        cout << ans << endl;
    }

    return 0;
}