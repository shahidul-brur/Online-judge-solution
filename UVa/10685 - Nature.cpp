//Accepted

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
int base[5002], totalFriends[5002];
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
    freopen("10685.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, C, R, i, maxi;
    string name1, name2;
    map<string, int> id;
    while(cin>>C)
    {
        cin>>R;
        if(C==0 && R==0)
            break;
        for(i=0;i<C;i++)
        {
            cin>>name1;
            id[name1]=i;
        }
        for(i=0;i<C;i++)
            base[i]=i, totalFriends[i]=1;
        maxi=1;
        while(R-- >0)
        {
            cin>>name1>>name2;
            makeFriend(id[name1], id[name2]);
            if(totalFriends[base[id[name1]]]>maxi)
                maxi=totalFriends[base[id[name1]]];
        }
        cout<<maxi<<endl;
        id.clear();
    }
    return 0;
}
