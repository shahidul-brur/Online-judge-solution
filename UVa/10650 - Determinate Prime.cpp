//Accepted

#include<bits/stdc++.h>
using namespace std;
bool st[32010];
vector<int> prime, seq[200];
int sz, s;
void sieve(int n)
{
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(st[i]==0)
        {
            prime.push_back(i);
            for(int j=i+i;j<=n;j+=i) st[j]=1;
        }
    }
    sz=prime.size();
}
void findSeq()
{
    s=0;
    for(int k=0;k<sz-2;)
    {
        int d = prime[k+1] - prime[k];
        if(prime[k+2] - prime[k+1]==d)
        {
            int l = k+2, last=k+2;
            while(prime[l]-prime[l-1]==d)
            {
                last = l;
                l++;
                if(l>=sz)
                    break;
            }
            seq[s].push_back(prime[k]);
            for(int m=k+1;m<=last;m++)
                seq[s].push_back(prime[m]);
            k=last;
            s++;
        }
        else k++;
    }
}
int main()
{
    sieve(32005);
    findSeq();
    int a, b, i, j;

    while(cin>>a>>b)
    {
        if(a==0 && b==0)
            break;
        a = abs(a);
        b = abs(b);
        if(a>b)
            swap(a, b);
        if(a<2)
            a = 2;
        for(i=0;i<s;i++)
        {
            if(seq[i][0]>=a)
                break;
        }
        for(j=s-1;j>=0;j--)
        {
             if(seq[j][seq[j].size()-1]<=b)
                break;
        }
        for(int k=i;k<=j;k++)
        {
            cout << seq[k][0];
            int siz = seq[k].size();
            for(int m=1;m<siz;m++)
                cout << " " << seq[k][m];
            cout << "\n";
        }
    }
    return 0;
}
