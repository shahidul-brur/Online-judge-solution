/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    freopen("696.txt", "r", stdin);
	int t, i, j, k, m, n, total, cas;
	while(scanf("%d %d", &m, &n)!=EOF)
	{
		if(m==0 && n==0)
            break;
		if(m == 1)
			total = n;
		else if(n == 1)
			total = m;
		else if(n == 2)
		{
			total = (m / 4) * 4;
			if(m % 4 == 1)
				total += 2;
			else if(m % 4 > 1)
				total += 4;
		}
		else if(m == 2)
		{
			total = (n / 4) * 4;
			if(n%4==1)
				total+=2;
			else if(n%4>1)
				total+=4;
		}
		else
			total=(m*n)/2 + (m*n)%2;
		printf("%d knights may be placed on a %d row %d column board.\n", total, m, n);
	}

	return 0;
}
/**********************************************************
About this problem:

************************************************************/
