#include <bits/stdc++.h>
using namespace std;

int main()
{
    //fast;
    //in;
    //out;
    int n, a[105], i, c, j,one=0;
    long long s;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
        if(a[i]==1)
             one=1;
    }
    s=one;
    for(i=0;i<n-1;i++)
    {
    	if(a[i]==1)
    	{
    		c=1;
    		for(j=i+1;j<n&&a[j]==0;j++)
	    	{
	    		c++;
	    	}
	    	if(j<n && a[j]==1)
	    		s*=c;
    	}
    }
	cout << s << "\n";
    return 0;
}