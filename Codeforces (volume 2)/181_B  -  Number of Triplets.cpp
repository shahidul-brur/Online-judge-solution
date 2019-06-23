#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>, bool> m;
bool have[2010][2010];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, j, x[3005], y[3005];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        x[i]+=1000;
        y[i]+=1000;
        have[x[i]][y[i]]=1;
        //m[make_pair(x[i], y[i])]=1;
    }

    int cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((x[i]+x[j])%2==0 && (y[i]+y[j])%2==0)
            {
                //pair<int, int> mid = make_pair((x[i]+x[j])/2, (y[i]+y[j])/2);
                //cout << "  # " << mid.first << " " << mid.second <<"\n";
                if(have[(x[i]+x[j])/2][(y[i]+y[j])/2]==1)
                   cnt++;
            }
        }
    }
    cout << cnt << "\n";
    
    return 0;
}

