#include <bits/stdc++.h>
using namespace std;
const int MX = 100002;
int a[MX];

int main()
{
    int odd=0, even=0;
    vector<int> o, e;
    int k, n, p, oddNeed, evenNeed;
    cin>>n>>k>>p;
    evenNeed = p;
    oddNeed  = k - p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
        {
            odd++;
            o.push_back(a[i]);
        }
        else
        {
            even++;
            e.push_back(a[i]);
        }
    }
    if(odd<oddNeed || (odd - oddNeed)%2==1 || even + (odd - oddNeed)/2<evenNeed) cout << "NO\n";
    else
    {
        vector<int> oddAns[oddNeed+1], evenAns[evenNeed+1];
        int oddRem = odd, evenRem = even;
        int i, j;
        
        for(i = 0;i<oddNeed;i++)
        {
            oddAns[i].push_back(o[i]);
            oddRem--;
        }
        
        for(j = 0;j<even && j<evenNeed;j++)
        {
            evenAns[j].push_back(e[j]);
            evenRem--;
        }
        
        if(evenRem>0 && evenNeed>0)
        {
            for(;j<even;j++)
            {
                evenAns[0].push_back(e[j]);
                evenRem--;
            }
        }
        else 
        {
            for(;j<even;j++)
            {
                oddAns[0].push_back(e[j]);
                evenRem--;
            }
        }
        
        if(even<evenNeed)
        {
            for(int k = even;i<odd && k<evenNeed;i+=2, k++)
            {
                evenAns[k].push_back(o[i]);
                evenAns[k].push_back(o[i+1]);
                oddRem-=2;
            }
        }
        while(i<odd)
        {
            if(evenNeed>0)
            {
                evenAns[0].push_back(o[i++]);
                evenAns[0].push_back(o[i++]);
                oddRem-=2;
            }
            else
            {
                oddAns[0].push_back(o[i++]);
                oddAns[0].push_back(o[i++]);
                oddRem-=2;
            }
        }
        cout << "YES\n";
        for(int i = 0;i<oddNeed;i++)
        {
            int s = oddAns[i].size();
            cout << s ;
            for(int j = 0;j<s;j++)
                cout << " " << oddAns[i][j];
            cout << "\n";
        }
        for(int i = 0;i<evenNeed;i++)
        {
            int s = evenAns[i].size();
            cout << s ;
            for(int j = 0;j<s;j++)
                cout << " " << evenAns[i][j];
            cout << "\n";
        }
    }
    return 0;
}
