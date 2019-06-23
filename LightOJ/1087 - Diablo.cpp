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
#define LR    int lft = (node<<1), rgt = lft+1, mid = (b+e)/2
const int MX = 400002;
int arr[MX], n, q;
int tree[MX*4];
void build(int node, int b, int e)
{
	if(b==e)
	{
		if(b>n)
			tree[node] = 0;
		else tree[node] = 1;
		return;
	}
	LR;
	build(lft, b, mid);
	build(rgt, mid+1, e);
	tree[node] = tree[lft]+tree[rgt];
}

void update(int node, int b, int e, int pos, int val)
{
	if(b==e && b==pos)
	{
		tree[node] = val;
		return;
	}
	LR;
	if(pos<=mid)
		update(lft, b, mid, pos, val);
	else update(rgt, mid+1, e, pos, val);
	tree[node] = tree[lft]+tree[rgt];
}
int query(int node, int b, int e, int k)
{
	if(b==e)
		return b;
	LR;
	if(tree[lft]>=k)
	{
		return query(lft, b, mid, k);
	}
	else if(tree[lft]<k)
	{
		return query(rgt, mid+1, e, k - tree[lft]);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	scanf("%d", &t);
	for(int cas = 1;cas<=t;cas++)
	{
		scanf("%d %d", &n, &q);
		for(int i = 1;i<=n;i++)
		{
			scanf("%d", &arr[i]);;
		}
		int tot = n+q;
		build(1, 1, tot);
		int cur = n;
		printf("Case %d:\n", cas);
		while(q--)
		{
			char cmd;
			int p;
			scanf("\n%c %d", &cmd, &p);
			if(cmd=='a')
			{
				arr[++cur] = p;
				update(1, 1, tot, cur, 1);
			}
			else
			{
				int pos = query(1, 1, tot, p);
				if(tree[1]<p)
					printf("none\n");
				else 
				{
					printf("%d\n",arr[pos]);
					update(1, 1, tot, pos, 0);
				}
			}
		}
	}
	return 0;
}

