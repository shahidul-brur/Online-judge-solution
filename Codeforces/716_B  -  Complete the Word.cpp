#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 1000000
int pos[35];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, from, cnt;
    string s;
    while(cin>>s)
    {
        int l = s.length();
        F(i, 0, 29)
            pos[i] = -1;
        from = 0;
        cnt = 0;
        int to = -1;
        F(i, 0, l-1)
        {
            if(s[i]!='?')
            {
                
                int p = s[i] - 'A';
                //cout << pos[p] << " -> ";
                if(pos[p]==-1)
                {
                    pos[p] = i;
                    cnt++;
                }
                else 
                {
                    int pre = pos[p];
                    int rej = 0;
                    for(j=pre;j>=from;j--)
                    {
                        if(s[j]!='?')
                        {
                            int pp = s[j] - 'A';
                            pos[pp] = -1;
                        }
                        rej++;
                    }
                    pos[p] = i;
                    
                    //cout << rej << "\n";
                    from = pre+1;
                    cnt = i-pre;
                }
                //cout << pos[p] << " " << cnt << "\n";
            }
            else cnt++;
            
            if(cnt == 26)
            {
                //cout << from <<"\n";
                to = i;
                for(j=from;j<=to;j++)
                {
                    if(s[j]=='?')
                    {
                        for(int k=0;k<26;k++)
                        {
                            if(pos[k]==-1)
                            {
                                char ch = k+'A';
                                s[j] = ch;
                                pos[k] = j;
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
        if(to==-1)
        {
            cout << "-1\n";
        }
        else
        {
            F(i, 0, l-1)
            {
                if(s[i]=='?')
                    s[i] = 'A';
            }
            cout << s << "\n";
        }
    }
    return 0;
}

