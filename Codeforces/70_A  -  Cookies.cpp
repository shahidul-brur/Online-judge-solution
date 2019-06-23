#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int main()
{
    int n;
    int ans = 1;

    scanf("%d", &n);

    for(int i = 1; i < n; i++)
        ans = ans * 3 % 1000003;

    printf("%d", ans);

    return 0;
}