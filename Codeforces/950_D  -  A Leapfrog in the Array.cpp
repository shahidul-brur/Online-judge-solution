/*=================================*\
								   
	  Md. Shahidul Islam		   
		 CSE, BRUR				 
	  Rangpur, Bangladesh		  
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur		
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English) 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll solve(ll x)
{
	if(x%2==1) return (x+1)/2;
	return solve(x + n - x/2);
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin>>n>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		cout << solve(x) << "\n";
	}
	return 0;
}
