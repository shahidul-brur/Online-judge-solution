/*==============================================*\ 
ID:          shahidul_brur
Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
 mail: shahidul.cse.brur@gmail.com 
 FB  : www.fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    ll gcd = __gcd(x,y);
    x/=gcd;
    y/=gcd;
    cout << min(a/x, b/y);
    return 0;
}