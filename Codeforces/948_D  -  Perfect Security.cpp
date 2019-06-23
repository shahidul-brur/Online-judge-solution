/*=================================*\
								   
	  Md. Shahidul Islam		   
		 CSE, BRUR				 
	  Rangpur, Bangladesh		  
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur		
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English) 
\*=================================*/
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MAX = 10000002;
int trie[MAX][2], sizT=1;//initially have 1,root=1
int freq[MAX][2];
int root = 1;
void buildTrie(int n){
    int v = root;
   // cout << n << "\n=====\n";
    for (int i = 30; i >=0 ; i--) {
        int c = ((n & (1<<i))>0);
        freq[v][c]++;
       // cout << trie[v][c] << " : ";
        if (trie[v][c] == -1) 
			trie[v][c] = ++sizT;
        v = trie[v][c];
        //cout << v << " ..\n";
    }
}
int searchTrie(int n){
    int v = root;
    int num = 0;
    for (int i = 30; i >=0 ; i--) {
        int c = ((n & (1<<i))>0);
        //cout << c << " : ";
        if (trie[v][c] == -1 || (freq[v][c]<1)){
			c^=1;
        }
       // cout << c << "\n";
		if(c == 1)
			num = num | (1<<i);
		else num &= ~(1 << i);
		freq[v][c]--;
		v = trie[v][c];
    }
    return num;
}
int a[300005];
int k[300005];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	mem(trie, -1);
	mem(freq, 0);
	f(i, 1, n)
	{
		cin>>a[i];
	}
	f(i, 1, n)
	{
		cin>>k[i];
		buildTrie(k[i]);
	}
	f(i, 1, n)
	{
		int x = searchTrie(a[i]);
		int val = a[i] ^ x;
		//cout << a[i] << " " << val << " : " << x << ".\n"; 
		cout << val << " ";
	}
	return 0;
}

