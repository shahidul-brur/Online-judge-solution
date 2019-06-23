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
ll a[505][505], r[505], c[505], d1, d2, sum, add;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, row, col;
    
    while(cin>>n)
    {
        if(n==1)
        {
            cin>>a[1][1];
            cout << "1\n";
            break;
        }
        else
        {
            F(i, 0, n-1)
            {
               F(j, 0, n-1)
                {
                    cin>>a[i][j];
                    if(a[i][j]==0)
                    {
                        row=i;
                        col=j;
                    }
                }
            }
            
            F(i, 0, n-1)
            {
                F(j, 0, n-1)
                {
                    r[i]+=a[i][j];
                }
            }
            
            F(i, 0, n-1)
            {
                F(j, 0, n-1)
                {
                    c[i]+=a[j][i];
                }
            }
            
            if(row==0)
            {
                sum = r[1];
            }
            else
            {
                sum = r[0];
            }
            
            add = sum - r[row];
            if(add<=0)
            {
                cout << "-1\n";
                return 0;
            }
            r[row]+=add;
            c[col]+=add;
            a[row][col] = add;
            
            int y=1;
            F(i, 0, n-1)
            {
                if(r[i]!=sum)
                {
                    y=0;
                    break;
                }
            }
            F(i, 0, n-1)
            {
                if(c[i]!=sum)
                {
                    y=0;
                    break;
                }
            }
            
            F(i, 0, n-1)
            {
                d1+=a[i][i];
            }
            if(d1!=sum)
            {
                y=0;
            }
            
            i = 0;
            j = n-1;
            for(;i<n;i++, j--)
            {
                d2+=a[i][j];
            }
            
            if(d2!=sum)
            {
                y=0;
            }
            if(y==1)
                cout << add << "\n";
            else cout << "-1\n";
        }
    }
    return 0;
}

