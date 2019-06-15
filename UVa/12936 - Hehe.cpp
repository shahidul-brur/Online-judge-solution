/**********************************************************
Status:     Accepted
Problem:    UVa 12936
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
***********************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
struct conversation
{
	int hehe;
	char p1[1002], p2[1002];

};

conversation conv[102];
void makelower(char *s)
{
	int l = strlen(s);
	for (int i = 0; i<l; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
}
int main()
{
	//freopen("in.txt", "r", stdin);
	char name1[1002], name2[1002], inp[1002], word[1002];
	int i, j, len, len1, len2, con, h, cnt, w;
	con = 0;
	while (gets(inp))
	{
		makelower(inp);
		len = strlen(inp);

		for (i = 0, len1 = 0; i<len && inp[i] != '-'; i++)
			name1[len1++] = inp[i];
		name1[len1] = '\0';

		for (i = i + 2, len2 = 0; i<len && inp[i] != ':'; i++)
			name2[len2++] = inp[i];
		name2[len2] = '\0';

		h = 0;
		for (i = i + 2, w=0; i<=len; i++)
		{
			if (inp[i]>='a' && inp[i]<='z')
			{
				word[w++] = inp[i];
			}
			else
			{
				word[w] = '\0';
				int yes = 1;
				if (w>0 && w % 2 == 0)
				{
					for (j = 0; j < w - 1;j+=2)
						if (word[j] != 'h')
						{
							yes = 0;
							break;
						}
					for (j = 1; j < w ; j+=2)
						if (word[j] != 'e')
						{
							yes = 0;
							break;
						}
				}
				else yes = 0;
				if (yes == 1)
				{
					h = 1;
					break;
				}
				w = 0;
				while (inp[i]<'a' || inp[i]>'z')
					i++;
				i--;
			}
		}
		int prev = 0;
		for (i = 0; i<con; i++)
		{
			if ((strcmp(name1, conv[i].p1) == 0 && strcmp(name2, conv[i].p2) == 0) || (strcmp(name1, conv[i].p2) == 0 && strcmp(name2, conv[i].p1) == 0))
			{
				conv[i].hehe = h;
				prev = 1;
				break;
			}
		}

		if (prev == 0)
		{
			conv[con].hehe = h;
			strcpy(conv[con].p1, name1);
			strcpy(conv[con].p2, name2);
			con++;
		}
	}
	cnt = 0;
	for (i = 0; i < con; i++)
	{

		cnt += conv[i].hehe;
	}

	printf("%d%%\n", cnt*100/con);
	return 0;
}

