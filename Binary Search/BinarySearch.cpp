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
int Binary_Search(int arr[] , int n, int target) {
    int low = 0;
    int high = n-1;
    
    while(low<=high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) 
        return mid;

        else if(arr[mid] > target)
        high = mid-1;

        else
        low = mid+1;
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

    int arr[] = {10, 12, 20, 30, 34, 54};  
    
    int k = Binary_Search(arr, 6, 12);

    cout << k << endl;
    return 0;
}