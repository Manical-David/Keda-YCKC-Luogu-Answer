#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll phi(ll x)
{
	ll ans=x;
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
		{
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}
int main()
{
	int T; cin>>T;
	while(T--)
	{
		ll a,b; cin>>a>>b;
		ll bin = __gcd(a, b);
		printf("%lld\n",phi(b/bin));
	}
	return 0;
}