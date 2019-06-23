#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
//template<typename dtype> using ordered_set = tree<dtype, null_type, less<dtype>, rb_tree_tag, tree_order_statistics_node_update>;

class Timer {
    clock_t start;
    string name;
public:
    Timer() {name = "";start = clock();}
    Timer(string s){name = s;start = clock();}
    ~Timer() {fprintf(stderr, "%s: %.3gs\n", name.c_str(), 1.0*(clock() - start) / CLOCKS_PER_SEC);}
};

//#define isValid(a, b) (a >= 0 && a < b)
//int dr[]  =  {0, -1, -1, -1,  0,  1, 1, 1};
//int dc[]  =  {1,  1,  0, -1, -1, -1, 0, 1};

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define what_is(x) cerr << fixed << setprecision(2) << boolalpha << #x << " = " << x << endl

const double EPS = 1e-9;
const long double PI = acos(-1.0L);

template<typename dtype> inline dtype sq(dtype a){return a*a;}
template<typename dtype1, typename dtype2> inline pair<dtype1, dtype2> mp(dtype1 a, dtype2 b){return make_pair(a, b);}
template<typename dtype1, typename dtype2> inline dtype1 safeMod(dtype1 a, dtype2 m){return (a%m + m)%m;}/*handling negative sign of remainder*/
template<typename dtype1, typename dtype2> inline bool isEq(dtype1 a, dtype2 b){return abs(a - b) < EPS;}
template<typename dtype1, typename dtype2, typename dtype3> inline bool isEq(dtype1 a, dtype2 b, dtype3 eps){return abs(a - b) < eps;}
template<typename dtype> inline dtype toRad(dtype deg){return deg*PI/180.0;}
template<typename dtype> inline dtype toDeg(dtype rad){return rad*180.0/PI;}
template<typename dtype> inline bool isKthBitOn(dtype n, int k){assert(n <= numeric_limits<dtype>::max());assert(k<=numeric_limits<dtype>::digits);dtype ONE = 1;return bool((n & (ONE<<k)));}
template<typename dtype> inline void setKthBit(dtype& n, int k){assert(n <= numeric_limits<dtype>::max());assert(k<=numeric_limits<dtype>::digits);dtype ONE = 1;n = (n|(ONE<<k));}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const int MAX = 200010;
const int MOD = 1000000007;
const int precision = 10;

vi j2i[MAX];
    int a[MAX], b[MAX];
int main(int argc, char* argv[])
{
    #ifdef NAbdulla
    //assert(freopen("in.txt", "r", stdin));
    //assert(freopen("out.txt", "w", stdout));
    #endif // NAbdulla
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //cout << fixed << setprecision(precision);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        j2i[a[i]].pb(i);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= k; i++)
        sort(j2i[i].begin(), j2i[i].end(), [b](int x, int y){return b[x] < b[y];});
    int done = 0;
    vector<int> vv;
    for(int i = 1; i <= k; i++){
        if(j2i[i].size()){
            done++;
            for(int j = 0; j < j2i[i].size()-1; j++){
                vv.push_back(b[j2i[i][j]]);
            }
        }
    }
    ll ext = 0;
    sort(vv.begin(), vv.end());
    for(int i = 0; i < vv.size() && done < k; i++){
        ext += vv[i];
        done++;
    }
    cout << ext << endl;
    return 0;
}
