/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;
int minExpSalary[1005];
int offeredSalary[1005];
bool employed[1005];
bool qualified[1005][1005];
int maxJobOffer[1005];
pair<int, int> salary[1005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        mem(employed, 0);
        int candidate, company;
        cin>>candidate>>company;
        f(i, 1, candidate)
            cin>>minExpSalary[i];
        f(j, 1, company)
        {
            cin>>offeredSalary[j]>>maxJobOffer[j];
            salary[j].first = offeredSalary[j];
            salary[j].second = j;
        }
        
        sort(salary+1, salary+company+1);
        
        f(i, 1, candidate)
        {
            string s;
            cin>>s;
            f(j, 0, company-1)
                qualified[i][j+1] = s[j] - '0';
        }
                
        int gotJob = 0;
        ll totalSalary = 0LL;
        int noEmployee = 0;
        
        f(i, 1, candidate)
        {
            //cout << "Candidate : " << i << "\n.............\n";
            F(j, company, 1)
            {
                if(maxJobOffer[salary[j].second]>0 && salary[j].first>=minExpSalary[i] 
                   && qualified[i][salary[j].second]==1)
                {
//                    cout << "    selected at company : " << salary[j].second << "\n";
//                    cout << "    offered salary      : " << salary[j].first << "\n";
//                    cout << "    remaining job offer : " << maxJobOffer[salary[j].second] << "\n\n";
                    employed[salary[j].second] = 1;
                    gotJob++;
                    totalSalary+=(ll)salary[j].first;
                    maxJobOffer[salary[j].second]--;
                    break;
                }
            }
        }
        f(j, 1, company)
            if(employed[j]==0)
                noEmployee++;
        cout << gotJob << " " << totalSalary << " " << noEmployee << "\n";
    }
    return 0;
}


