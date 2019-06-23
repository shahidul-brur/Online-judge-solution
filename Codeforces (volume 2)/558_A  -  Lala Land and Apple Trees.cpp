#include <bits/stdc++.h>
using namespace std;
int t1[102], t2[102];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, s1, s2, x, a, mid, total;
    vector<pair<int, int> > apple;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        cin>>x>>a;
        apple.push_back(pair<int, int>(x, a));
    }
    sort(apple.begin(), apple.end());
    for(mid=0;mid<n && apple[mid].first<0;mid++);
    
    s1 = s2 = 0;
    
    for(int i=mid-1;;i--)
    {
        if(i<0)
            break;
        if(t1[i]==0)
        {
            s1+=apple[i].second;
            t1[i] = 1;
            int j;
            for(j=i+1;j<n;j++)
            {
                if(t1[j]==0)
                {
                    s1+=apple[j].second;
                    t1[j]=1;
                    i = j;
                    break;
                }
            }
            if(j>=n)
                break;
        }
    }
    
    
    for(int i=mid;;i++)
    {
        if(i>=n)
            break;
        if(t2[i]==0)
        {
            s2+=apple[i].second;
            t2[i] = 1;
            int j;
            for(j=i-1;j>=0;j--)
            {
                if(t2[j]==0)
                {
                    s2+=apple[j].second;
                    t2[j] = 1;
                    i = j;
                    break;
                }
            }
            if(j<0)
                break;
        }
    }
    total = max(s1, s2);
    printf("%d\n", total);
    return 0;
}