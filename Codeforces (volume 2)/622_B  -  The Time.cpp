#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m, a;
   scanf("%d:%d", &h, &m);
        scanf("%d", &a);
        m = h*60 + m + a;
        h = m/60;
        m = m%60;
        h = h%24;
        printf("%02d:%02d\n", h, m);
    return 0;
}
