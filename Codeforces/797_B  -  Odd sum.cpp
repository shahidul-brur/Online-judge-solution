#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,x,y,z,cnt=0,mn=2e9;
int main()
{
    cin>>n;
    int a[n+5];
    int even=0,odd=0,oddcnt=0;
    int maxodd=-2e5,minodd=2e5;
    for(i=0;i<n;i++) {
        cin>>x;
        if(x%2==0){
            if(x>0) even+=x;
        }
        else{
            if(x<0)
                maxodd=max(x,maxodd);
            
            else if(x>0) {
                minodd=min(x,minodd);
                cnt++; 
                odd+=x;
            }
        }
    }
    if(cnt==0) odd=maxodd;
    else if(cnt%2==0) {
        odd=max(odd-minodd,odd+maxodd);
    }
    cout<<even+odd;
}