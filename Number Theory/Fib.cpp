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
void multiply(ll  A[][2], ll B[][2], int size) {
    
    ll C[2][2];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size;j++)
           C[i][j] = 0;
       
    }
    for(int i=0;i<size;i++) {
        for(int j=0; j<size ;j++) {
            for(int k =0;k<size;k++)
            C[i][j] +=(A[i][k] * B[k][j]);
        }

    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size;j++)
           A[i][j] = C[i][j];
       
    }
}
void matrixExponentiation(ll A[][2], int size, int n) {
    if(n==1) return;

    ll B[2][2] = {{1, 1}, {1, 0}};
   
    matrixExponentiation(A, size, n/2);
    multiply(A, A, size);
    if(n%2)
    multiply(A, B, size);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/DSA_CPP/output.txt", "w", stdout);
    #endif

    ll n; cin >> n;

    if(n==0 || n==1) return n;

    ll A[2][2]={{1,1},{1,0} };

    matrixExponentiation(A, 2, n-1);
    cout << A[0][0] << endl;
    return 0;
}