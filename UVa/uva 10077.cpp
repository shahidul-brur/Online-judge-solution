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
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))

string find(int x, int y, int a = 0, int b = 1, int c = 1, int d = 0) {
	int m = a + c, n = b + d;
	if (x == m && y == n) return "";
	if (x * n <y * m)
		return 'L' + find(x, y, a, b, m, n);
	else
		return 'R' + find(x, y, m, n, c, d);
}
int main()
{
	freopen("in.txt", "r", stdin);
	int x, y, a, b, c, d;
	string str;
	while (scanf("%d %d", &x, &y) == 2)
	{
		if (x == 1 && y == 1)
			break;
		a = d = 0;
		b = c = 1;
		str = find(x, y, a, b, c, d);
		cout << str << endl;

	}
	return 0;
}


/**********************************************************
About this problem:

************************************************************/

