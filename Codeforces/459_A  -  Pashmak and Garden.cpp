#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))

bool valid(int x1, int y1, int x2, int y2)
{
    if(x1==x2 || y1==y2)
        return true;
    else if(abs(x1-x2)==abs(y1-y2))
        return true;
    return false;
}
int main()
{
    int x1, x2, y1, y2;
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2)!=EOF)
    {
        if(valid(x1, y1, x2, y2))
        {
            if(x1==x2)
            {
                if(x1+abs(y1-y2)>=-1000 && x1+abs(y1-y2)<=1000)
                    printf("%d %d %d %d\n", x1+abs(y1-y2), y1, x1+abs(y1-y2), y2);
                 else if(x1-abs(y1-y2)>=-1000 && x1-abs(y1-y2)<=1000)
                    printf("%d %d %d %d\n", x1-abs(y1-y2), y1, x1-abs(y1-y2), y2);
                else printf("-1\n");
            }
            else if(y1==y2)
            {
                if(y1+abs(x1-x2)>=-1000 && y1+abs(x1-x2)<=1000)
                    printf("%d %d %d %d\n", x1, y1+abs(x1-x2), x2, y1+abs(x1-x2));
                 else if(y1-abs(x1-x2)>=-1000 && y1-abs(x1-x2)<=1000)
                    printf("%d %d %d %d\n", x1, y1-abs(x1-x2), x2, y1-abs(x1-x2));
                else printf("-1\n");
            }
            else
            {
                printf("%d %d %d %d\n", x1, y2, x2, y1);
            }
        }
        else printf("-1\n");
    }
    return 0;
}
