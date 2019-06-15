//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<string> dic;
int charDiff(string a, string b)
{
    int len1=a.size();
    int len2=b.size();
    if(len1!=len2)
        return -1;
    else
    {
        int d=0;
        for(int i=0;i<len1;i++)
        {
            if(a.at(i)!=b.at(i))
                d++;
        }
        return d;
    }
}
int main()
{
    freopen("10508.txt", "r", stdin);
    int word, i, j,len, n, taken[100000];
    string from, to, A, B;
    map<string, int> mp;
    while(scanf("%d %d", &word, &len)==2)
    {
        memset(taken, 0, sizeof(taken));
        cin>>from;
        cin>>to;


        mp[from]=0;
        mp[to]=1;

        n=2;

        dic.push_back(from);
        dic.push_back(to);
        for(int k=0;k<word-2;k++)
        {
            cin>>A;
            dic.push_back(A);
            mp[A]=n++;
        }

        A=from;

        cout<<from<< "\n";
        while(A.compare(to)!=0)
        {
            for(j=0;j<n;j++)
            {
                B=dic.at(j);
                if(charDiff(A, B)==1 && taken[mp[B]]==0)
                {
                    cout<<B<< "\n";
                    taken[mp[A]]=1;
                    A=B;
                    break;
                }
            }
            if(A.compare(to)==0)
                break;
        }
        dic.resize(0);
        mp.clear();
    }
    return 0;
}
