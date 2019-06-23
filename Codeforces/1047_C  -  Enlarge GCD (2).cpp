/*==============================================*\ 
ID:          shahidul_brur

Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
                
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

const int M = 15000000;
bool is_composite[M+2];
int sp[M+2];
int koybar[970710][25];
int maap[M+2];
//vector<int> facts;
int c = 0;
int gcnt[970710];
//int fcnt[M+2];
void Sieve(){
	for (int i = 2; i <= M; i += 2)
        sp[i] = 2;
    maap[2] = ++c;
	for (ll i = 3; i <= M; i += 2){
		if (is_composite[i]) continue;
        sp[i] = i;
        maap[i] = ++c;
        //mpr = i;
        for (ll j = i; (j*i) <= M; j += 2){
            if (!is_composite[j*i]){
                is_composite[j*i] = true;
                sp[j*i] = i;
            }
        }
	}
}

void factorize(int n) // log n
{
    while(n>1){
        //facts.push_back(sp[n]);
        int tot = 1;
        int tem = n;
        while(tem%sp[n]==0)
            tem/=sp[n], tot++;
        koybar[maap[sp[n]]][tot]++;
        n = tem;
    }
}
void gf_cnt(int n)
{
    while(n>1){
        //facts.push_back(sp[n]);
        gcnt[maap[sp[n]]] = 1;
        int tem = n;
        while(tem%sp[n]==0){
            tem/=sp[n];
            gcnt[maap[sp[n]]]++;
        }
        n = tem;
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    Sieve();
    //cout << mpr << " " << c;
    set<int> s;
    int n;
    scanf("%d", &n);
    int g = 0;
    f1(i,n){
        int x;
        scanf("%d", &x);
        g =__gcd(x, g);
        s.insert(x);
        //cnt[a[i]]++;
        //if(!done[a[i]])
        if(x>1) factorize(x);
    }
    if((int)s.size()==1){
        printf("-1\n");
        return 0;
    }
    
    gf_cnt(g);
    f1(i,c)
    {
        fr(j, 23, 1)
        {
            koybar[i][j]+=koybar[i][j+1];
        }
    }
    int mini = n-1;
    f1(i,c)
    {
        int k = gcnt[i];
        int del = n - koybar[i][k+1];
        mini = min(mini, del);
    }
    printf("%d\n", mini);
    return 0;
}
