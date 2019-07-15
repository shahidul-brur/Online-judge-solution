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
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
class Solution {
public:
    int dp[1002][1002];
    int lenA,lenB, lcslen;
    string A, B, ans;
    string shortestCommonSupersequence(string str1, string str2) {
        lenA = str1.size(), lenB = str2.size();
        A = str1, B = str2;
        memset(dp,-1,sizeof(dp));
        lcslen = calcLCS(0,0);
        printLCS(0,0);
        string res;
        int i=0,j=0;
        f0(k,lcslen)
        {
            while(i<lenA && A[i]!=ans[k])
            {
                res+=A[i];
                i++;
            }
            i++;
            while(j<lenB && B[j]!=ans[k])
            {
                res+=B[j];
                j++;
            }
            j++;
            res+=ans[k];
        }
        while(i<lenA)
        {
            res+=A[i];
            i++;
        }
        while(j<lenB)
        {
            res+=B[j];
            j++;
        }
        return res;
    }
    int calcLCS(int i,int j)
    {	
        if(i==lenA || j==lenB) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(A[i]==B[j]) ans=1+calcLCS(i+1,j+1);
        else
        {
            int val1=calcLCS(i+1,j);
            int val2=calcLCS(i,j+1);
            ans=max(val1,val2);
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    
    void printLCS(int i,int j)
    {
        if(i==lenA || j==lenB) return;
        if(A[i]==B[j]){
            ans+=A[i];
            printLCS(i+1,j+1);
        }
        else
        {
            if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
            else printLCS(i,j+1);
        }
    }
};
