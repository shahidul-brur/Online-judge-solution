#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int B[10002];
	memset(B, 0, sizeof(B));
	int start, h, finish, n = 0, i, s, m;
	m = 0;
	while (cin>>start>>h>>finish)
	{
		if (finish > m)
			m = finish;
		n++;
		for (i = start+1; i <= finish; i++)
		{
			if (B[i] < h)
				B[i] = h;
		}
	}
	/*
    for(i=s;i<=m+1;i++)
        printf("%d = %d\n", i, B[i]);
    */
    if(B[2]==0)
        printf("1 0 ");
	for (i = 1; i <= m; i++)
	{
		if (B[i] != B[i - 1])
			printf("%d %d ", i-1, B[i]);
	}
    printf("%d %d\n", i-1, B[i]);
	return 0;
}

