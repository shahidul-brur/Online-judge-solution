#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define eps 1e-6
#define pi acos(-1)
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))

int main()
{
    //freopen("in.txt", "r", stdin);
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<string> v, inp;
    string s;
    int n, m, i, j, num[100005], out[1000005];
    cin>>n;
    F(i, 0, n-1)
    {
        cin>>s;
        inp.pb(s);
        if(s!="removeMin")
        {
        	cin>>num[i];
        }
    }
    m = 0;
    F(i, 0, n-1)
    {
        if(inp[i]=="insert")
        {
            pq.push(num[i]);
            v.pb(inp[i]);
            out[m++] = num[i];
        }
        else if(inp[i]=="removeMin")
        {
            if(pq.empty())
            {
                pq.push(0);
                v.pb("insert");
                out[m++]=0;
            }
            pq.pop();
            v.pb(inp[i]);
            m++;
        }
        else
        {
            int now = num[i];
            if(pq.empty())
            {
                pq.push(now);
                v.pb("insert");
                out[m++] = now;
            }
            else
            {int cur = pq.top();
            if(now!=cur)
            {
                if(now<cur)
                {
                    pq.push(now);
                    v.pb("insert");
                    out[m++] = now;
                }
                else
                {
                    while(pq.top()<now)
                    {
                        pq.pop();
                        v.pb("removeMin");
                        m++;
                        if(pq.empty())
                            break;
                    }
                    if(pq.empty() || pq.top()>now)
                    {
                        pq.push(now);
                        v.pb("insert");
                        out[m++] = now;
                    }
                    
                }
            }
            }
            v.pb(inp[i]);
            out[m++] = num[i];
        }
    }
    cout << v.size() << "\n";
    F(i, 0, v.size()-1)
    {
        cout <<v[i];
        if(v[i]!="removeMin")
            cout << " " << out[i];
        cout << "\n";
    }
    return 0;
}

