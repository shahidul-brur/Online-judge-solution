#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define F(a, b) for(i=a;i<=b;i++)
#define Fr(b, a) for(i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define all(x) x.begin(), x.end()

// ---------------- typedef ------------------------------
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

// --------------   template ends  ------------------------
vii vec;
int n, y;

int binarylower(int m,int l,int u)
{
	int mid;
    while(l<=u)
	{
        mid=(l+u)/2;
        if(vec[mid].first==m)
        {	
            u=mid-1;
        }
        else
        {     
            return mid;
        }
    }
    return l;
}
  
int binaryupper(int m,int l,int u)
{
	int mid,c;
   	while(l<=u)
	{
        mid=(l+u)/2;
        if(vec[mid].first==m)
        {
            l=mid+1;
        }
        else
        {	
            return mid;
        }
    }
   	return u;
  }
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test, cnt, s[1005], t[1005], i, j, k;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>s[i];
            
        //sort(s, s+n);
        
        for(i=1;i<=n;i++)
        {
            cin>>t[i];
            vec.pb(make_pair(t[i], i));
        }
        
        sort(all(vec));
        
        int res[1005];
        cnt = 0;
        for(i=0;i<n;i++)
        {
            int ind1 = binaryupper(s[i], 0, vec.size()-1);
            int ind2 = binarylower(s[i], 0, vec.size()-1);
            if(vec[ind1].first==s[i] && vec[ind2].first==s[i])
            {
                cnt++;
            }
            //cout << ind << " ";
            if(vec[ind1].first!=s[i])
            {
                res[i] = vec[ind1].second;
                vec.erase(vec.begin()+ind1);
            }
            else
            {
                res[i] = vec[ind2].second;
                vec.erase(vec.begin()+ind2);
            }
        }
        vec.clear();
        cout << cnt << "\n";
        cout << res[0];
        for(i=1;i<n;i++)
            cout << " " << res[i];
        cout << "\n";
    }
    return 0;
}

