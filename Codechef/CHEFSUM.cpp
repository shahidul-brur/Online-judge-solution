/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
const int MX = 100005;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t, a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int m, idx = 1;
        cin>>m;
        f(i, 2, n) 
        {
            cin>>a;
            if(a<m) m=a, idx = i;
        }
        cout << idx << "\n";
    }
    return 0;
}

