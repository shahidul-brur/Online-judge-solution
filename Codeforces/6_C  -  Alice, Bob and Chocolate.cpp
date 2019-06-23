#include<bits/stdc++.h>
using namespace std;

int main()
  
{
  int n, t1[100005], t2[100005], t[100005];;
  int a, b;
  while(cin>>n)
  {
    t1[0] = t2[n+1] = 0;
    a = 0, b= 0;
  	for(int i = 1;i<=n;i++)
    {
      cin>>t[i];
      t1[i]=t1[i-1]+t[i];
    }
    for(int i = n;i>=1;i--)
    {
      t2[i]=t2[i+1]+t[i];
    }
    
    int tot = t[n];
    
    if(n==1)
    	cout << "1 0\n";
    else if(n==2)
       cout << "1 1\n";
    else
    {
        for(int i = 1;i<=n;i++)
        {
          if(t1[i-1]+1<=t2[i+1]+1)
            a++;
          else break;
        }
        cout << a << " " << n-a << "\n";
        return 0;
      }
  }
  return 0;
}
