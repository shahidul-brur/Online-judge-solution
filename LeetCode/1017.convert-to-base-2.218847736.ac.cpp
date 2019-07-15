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
const int maxn = 30002;
const int LOGN = 20;
class Solution {
public:
    string toString(int n) 
    { 
        string str; 
        stringstream ss; 
        ss << n; 
        ss >> str; 
        return str; 
    }
    string baseNeg2(int N) {
        if (N == 0) 
        return "0"; 
  
    string converted = ""; 
    int negBase = -2;
    while (N != 0) 
    { 
        int remainder = N % negBase; 
        N /= negBase; 
  
        if (remainder < 0) 
        { 
            remainder += (-negBase); 
            N += 1; 
        } 
  
        converted = toString(remainder) + converted; 
    } 
    return converted; 
    }
};
