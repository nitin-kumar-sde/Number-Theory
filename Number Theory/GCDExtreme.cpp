#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long
ll phi[MAX+1] = {0};
ll sieve[MAX+1] = {0};
ll ans[MAX+1] = {0};

void buildPhi() {
    for(int i=0;i<=MAX;i++) phi[i]=i;

    for(int i=2;i<=MAX;i++) {
        if(phi[i]==i) {
            for(int j=i;j<=MAX;j+=i)
            phi[j]=(phi[j]*(i-1))/i;
            
        }
    }

    for(int i=1;i<=MAX;i++) {
        for(int j=2*i;j<=MAX;j+=i) {
            sieve[j]+=(i*phi[j/i]);
        }
   }

    for(int i=1;i<=MAX;i++)
    ans[i]=ans[i-1]+sieve[i];
}

int main() {
   buildPhi();

    while(1) {
        ll n; cin>>n;
        if(n==0)
        break;
           
        ll fans=ans[n];
        cout<<fans<<endl;  
    }
	
}
