#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long N,B,i,j,p,c,noz,k;
      cin>>N>>B;
      j = B;
      noz=N;
      ll r = sqrt(B);
      while(r*r<B) ++r;
      while(r*r>B) --r;
      for (i=2;i<=r;i++)
      {
          if (j%i==0)
          {   
             p=0;
             while (j%i==0){
                   p++;
                   j/=i;
             }
             c=0;
             k=N;
             while (k/i>0){
                   c+=k/i;
                   k/=i;
             }
             noz=min(noz,c/p);
          }
          r = sqrt(j);
          while(r*r<j) ++r;
          while(r*r>j) --r;
      }
      if(j>1){
           i = j;
            p=0;
             while (j%i==0){
                   p++;
                   j/=i;
             }
            c=0;
             k=N;
             while (k/i>0){
                   c+=k/i;
                   k/=i;
             }
             //cout << c << " , ";
             noz=min(noz,c/p);
      }
      cout << noz;
      return 0;

}