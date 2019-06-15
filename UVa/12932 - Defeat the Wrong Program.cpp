/**********************************************************
Status:     Accepted
Problem:    UVa 12932
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
***********************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m, r, c, cas=1, i, j, ara[502][502], rowsum[502], colsum[502], user,cm, rm, maxi;
	while (scanf("%d %d", &n, &m)!=EOF)
	{
		rm = cm = -1;
		r = c = 0;
		for (i = 0; i < n; i++)
		{
			rowsum[i] = 0;
			for (j = 0; j < m; j++)
			{
				if (i == 0)
					colsum[j] = 0;
				scanf("%d", &ara[i][j]);
				rowsum[i] += ara[i][j];
				colsum[j] += ara[i][j];
				if (i == n - 1)
				{
					if (colsum[j]>cm)
					{
						cm = colsum[j];
						c = j;
					}
				}
			}
			if (rowsum[i]>rm)
			{
				rm = rowsum[i];
				r = i;
			}
		}
		user = rm + cm - ara[r][c];
		maxi = -1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (rowsum[i] + colsum[j] - ara[i][j]>maxi)
					maxi = rowsum[i] + colsum[j] - ara[i][j];
			}
		}
		if (user == maxi)
			printf("Case %d: Weak\n", cas);
		else printf("Case %d: Strong\n", cas);
		cas++;
	}
	return 0;
}
