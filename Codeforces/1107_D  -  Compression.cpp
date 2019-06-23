#include<bits/stdc++.h>
using namespace std;
const int maxn=5205;

bitset<maxn>rows[maxn];
bitset<maxn>cols[maxn];

int main(){
  ios::sync_with_stdio(0),cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;++i){
    string str;
    cin>>str;
    
    for(int j=0;j<n/4;++j){
      int num=isdigit(str[j])?str[j]-'0':str[j]-'A'+10;
      for(int k=0;k<4;++k){
        rows[i][4*j+k]=num>>(3-k)&1;
      }
    }

    for(int j=0;j<n;++j){
      cols[j][i]=rows[i][j];
    }
  }
  int ans=1;
  for(int i=2;i<=n;++i){
    if(n%i)continue;
    bool ok=true;
    for(int j=0;j<n;j+=i){
      for(int k=1;k<i;++k){
        ok&=rows[j]==rows[j+k];
        ok&=cols[j]==cols[j+k];
      }
    }
    if(ok) ans=i;
  }
  cout<<ans;
}