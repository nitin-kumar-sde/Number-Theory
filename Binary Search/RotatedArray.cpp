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

int search(int arr[], int n, int target) {
    
    int low = 0;
    int high = n-1;
    
    while(low <= high) {
        int mid = (low + high)/2;
    
        if(arr[mid] == target) return mid;
    
        if(arr[mid] < arr[high]) {
                
        // right sorted array
        if(target > arr[mid] && target <= arr[high])
            low = mid + 1;
        else high = mid-1;
        }
        // left sorted array
        if(arr[low] < arr[mid]) {
        
            if(target >= arr[low] && target < arr[mid])
            high = mid-1;
            else 
            low = mid+1;
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

    int arr[6] = {5, 6 ,7, 2 , 3, 4};
    int index = search(arr, 6, 3);
    cout << index << " is the index in given element";
    return 0;
}