//Accepted

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
int base[200002], totalFriends[200002];
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
    freopen("11503.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, F, i, j, L;
    string name1, name2;
    map<string, int> id;
    cin>>t;
    while(t-->0)
    {
        cin>>F;
        L=0;
        for(i=0;i<=2*F;i++)
            base[i]=i, totalFriends[i]=1;
        while(F-- >0)
        {
            cin>>name1>>name2;
            if(id.find(name1)==id.end())
                id[name1]=L++;
            if(id.find(name2)==id.end())
                id[name2]=L++;
            makeFriend(id[name1], id[name2]);
            cout<<totalFriends[base[id[name2]]]<<endl;
        }
        id.clear();
    }
    return 0;
}
