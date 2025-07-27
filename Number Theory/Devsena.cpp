#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define MOD 1000000007
#define MOD2 1000000006

// modular exponentiation
ll power(ll a,ll b, ll M) {
    if(b==0) return 1;
    ll ans=power(a,b/2,M);
    ans=(ans*ans)%M;
    if(b%2==1) ans=(ans*a)%M;
    return ans;
}


int main()
{
    int t; cin>>t;
    while(t--) {
     ll n; cin>>n;
     
    ll* freq=new ll[1+MAX];
        for(int i=0;i<=MAX;i++) freq[i]=0;
        ll mx_el=0;
        for(int i=0;i<n;i++) {
            ll temp; cin>>temp;
            freq[temp]++;
            mx_el=max(mx_el,temp);
        }

        ll * n_gcd=new ll[1+mx_el];
        for(int i=0;i<=mx_el;i++) n_gcd[i]=0;

        ll ans=1;
      
        for(int i= mx_el;i>=1;i--) { 
            ll s=freq[i], t=0;
            for(int j=2*i;j<=mx_el;j+=i) {
                s=s+freq[j];
                t=(t+n_gcd[j])%MOD2;
            }
            n_gcd[i]=power(2,s,MOD2)-1;
            n_gcd[i]=(n_gcd[i]-t)%MOD2;
            n_gcd[i]=(n_gcd[i]+MOD2)%MOD2;
            ans=(ans*power(i,n_gcd[i],MOD))%MOD;
        }
     
        cout<<ans<<endl;
        
    }
    
  return 0;
	
}
