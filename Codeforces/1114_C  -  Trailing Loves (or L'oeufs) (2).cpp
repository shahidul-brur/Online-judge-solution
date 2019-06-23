#include<bits/stdc++.h>
using namespace std;
/*const int MX = 1000003;
bool comp[MX];
//int sp[MX];
vector<int> facts, primes;
void Sieve(){
    comp[1] = 1;
    //sp[2] = 2;
    primes.pb(2);
    for (int i = 4; i < MX; i += 2){
        //sp[i] = 2;
        comp[i] = 1; // even numbers have smallest prime factor 2
    }
    for (int i = 3; i < MX; i += 2){
        if (comp[i]) continue;
        primes.pb((int)2);
        //sp[i] = i; // prime number itself its smallest prime factor
        for (ll j = (ll)i; (j*i) < MX; j += 2){
            if (!comp[j*i]){
                comp[j*i] = true;
                //sp[j*i] = i;
            }
        }
    }
}*/
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //Sieve();
    long long N,B,i,j,p,c,noz,k;
      cin>>N>>B;
      j = B;
      noz=N;
      //int p = pimes.size();
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