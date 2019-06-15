//Accepted

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
int base[30002], totalFriends[30002];
int findBaseFriend(int f)
{
    if(base[f]==f) return f;
    return base[f]=findBaseFriend(base[f]);
}
void makeFriend(int a, int b)
{
    int b1, b2;
    b1=findBaseFriend(a);
    b2=findBaseFriend(b);
    if(b1!=b2)
    {
        base[b1]=b2;
        totalFriends[b1]+=totalFriends[b2];
        totalFriends[b2]=totalFriends[b1];
    }
}
int main()
{
    freopen("10608.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, C, R, i, a, b, maxi;
    cin>>t;
    while(t--)
    {
        cin>>C>>R;
        if(C==0 && R==0)
            break;
        for(i=0;i<C;i++)
            base[i]=i, totalFriends[i]=1;
        maxi=1;
        while(R-- >0)
        {
            cin>>a>>b;
            makeFriend(a, b);
            if(totalFriends[base[a]]>maxi)
                maxi=totalFriends[base[a]];
        }
        cout<<maxi<<endl;
    }
    return 0;
}
