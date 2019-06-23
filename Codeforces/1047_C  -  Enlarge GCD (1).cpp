#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 15000000;
bool is_composite[M+2];
int sp[M+2];          // smallest prime factor of i
int freq[970710][25]; // freq[i][j] = k means that there are k numbers in array
                     //  in which i'th prime occurs j or more times
int maap[M+2]; // maap[i] = k means that i is k'th prime
int c = 0;    //  number of prime
int cnt[970710]; // cnt[i] = frequency of i'th prime in gcd
void Sieve(){
    for (int i = 2; i <= M; i += 2)
        sp[i] = 2;
    maap[2] = ++c;
    for (ll i = 3; i <= M; i += 2){
        if (is_composite[i]) continue;
        sp[i] = i;
        maap[i] = ++c;
        for (ll j = i; (j*i) <= M; j += 2){
            if (!is_composite[j*i]){
                is_composite[j*i] = true;
                sp[j*i] = i;
            }
        }
    }
}

void factorize(int n)
{
    while(n>1){
        int tot = 0, pf = sp[n];
        while(n%pf==0)
            n/=pf, tot++;
        freq[maap[pf]][tot]++;
    }
}
void prime_in_gcd(int n)
{
    while(n>1){
        int pf = sp[n];
        while(n%pf==0)
            n/=pf, cnt[maap[pf]]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    Sieve();
    set<int> s;
    int n;
    scanf("%d", &n);
    int g = 0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d", &x);
        g =__gcd(x, g);
        s.insert(x);
        factorize(x);
    }
    if((int)s.size()==1){
        printf("-1\n");
        return 0;
    }
    
    prime_in_gcd(g);
    for(int i=1;i<=c;i++)
        for(int j =23;j>=1;j--)
            freq[i][j]+=freq[i][j+1];

    int mini = n-1;
    for(int i=1;i<=c;i++){
        int k = cnt[i];
        int del = n - freq[i][k+1];
        mini = min(mini, del);
    }
    printf("%d\n", mini);
    return 0;
}