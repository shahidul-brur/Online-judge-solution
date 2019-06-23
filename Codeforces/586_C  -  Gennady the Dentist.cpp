#include<bits/stdc++.h>
using namespace std;
const int MX = 1000000;
struct child{
    long long vol_doc, vol_hall, conf; 
}childs[4005];

bool went[4005];
long long all = 0;
int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n, w;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>childs[i].vol_doc;
        cin>>childs[i].vol_hall;
        cin>>childs[i].conf;
    }
    for(int i = 1;i<=n;i++)
    {
        if(went[i]==1)
        {
            continue;
        }
        //cout << i << " :  " << childs[i].vol_doc << " ";
        //cout  << childs[i].vol_hall << " ";
        //cout  << childs[i].conf << ":\n================\n";
        long long d = childs[i].vol_doc;
        //cout << " *** " << d << " ***\n\n";
        int decr = 1;
        for(int j = i+1;d>=0 && j<=n;j++)
            if(went[j]==0)
                childs[j].conf-=(d--);
        d = 0;
        for(int j = i+1;j<=n;j++)
        {
            if(went[j]==1)
            {
                continue;
            }
            
            //cout << j << " :  " << childs[j].vol_doc << " ";
            //cout  << childs[j].vol_hall << " ";
            //cout  << childs[j].conf << " -> " << childs[j].conf-d << " ";
            childs[j].conf-=d;
            if(childs[j].conf<0)
            {
                went[j] = 1;
                d+=childs[j].vol_hall;
            }
            
            //cout << ", d = " << d;
            //cout << "\n";
        }
        //cout << "\n\n";
    }
    w = 0;
    for(int i =1;i<=n;i++)
        if(went[i]==0)
            w++;
     cout << w << "\n";
    for(int i = 1;i<=n;i++)
        if(went[i]==0)
             cout << i << " ";
    return 0;
}
