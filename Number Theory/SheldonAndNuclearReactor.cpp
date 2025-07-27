#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n; cin>> n;
    while(n--) {
        
        ll t, m; cin>>t >> m;

        ll ans=1;

        if((t/m)%2) ans = m-1;
        for(int i=1;i<=t%m;i++) ans=(ans*i)%m;
            
        cout<<ans<<endl;
        
    }
    return 0;
}
