#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 1000000
#define N 100005
int sieve[1+MAX];
ll phi[N];
ll arr[N];

vector<int> buildSieve() {

    for(int i=0;i<=MAX;i++)sieve[i]=1;
    sieve[0]=sieve[1]=0;
    for(int i=2;i*i<=MAX;i++)
    {
        if(sieve[i]) {
            for(int j=i*i;j<=MAX;j+=i)
            sieve[j]=0;
        }
    }
    vector<int> prime;
	for(int i=2;i<=MAX;i++) {
          if(sieve[i]) prime.push_back(i);
    }
    return prime;
}
int main() 
{ 

    vector<int> prime = buildSieve();

    int t; cin >> t;
    while(t--) { 
        ll l,r,k; cin >> l >> r >> k;
        
        for(int i=l;i<=r;i++) phi[i-l] = arr[i-l] = i;

        for(int i=0;prime[i]*prime[i]<=r;i++) {
            int  pr=prime[i];

            ll base=(l/pr)*pr;
            if(base<l) base+=pr;
            for(ll j=base;j<=r;j+=pr) {
               phi[j-l]=(phi[j-l]*(pr-1))/pr;
               while(arr[j-l]%pr==0)arr[j-l]/=pr;
            }           
        }
        for(int i=0;i<=r-l;i++)
        {
            if(arr[i]!=1)
            {
                phi[i]=(phi[i]*(arr[i]-1)/arr[i]);
            }
        }
        int count =0;
        for(int i=0;i<=r-l;i++) count+=(phi[i]%k==0);
        int size=r-l+1;
        float ans=(1.0*count)/size;
       cout << fixed << setprecision(6) << (double)ans << endl;
        
    }
    
	return 0;
}
