#include <iostream>
bool isRun(int n)
{
    int digit[8], d=0,last,p=0, cnt=0;
    while(n>0)
    {
        digit[d++]=n%10;
        n/=10;
    }
    last=digit[0];
    while(cnt<d)
    {
        p+=last;
        cnt++;
        p=p%(d-1);
        last=digit[p];
    }
    if(last==digit[0])
        return true;
    else return false;
}
using namespace std;

int main()
{
    int runaround[1000], i, r=0, n;
    for(i=1;i<=5;i++)
    {
        if(isRun(i))
            runaround[r++]=i;
    }
    cout<<r;
    return 0;
}
