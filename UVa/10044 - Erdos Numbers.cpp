/************************************************************
* Problem:     UVa 10044
* Link:        https://uva.onlinejudge.org/external/100/10044.html                                           
* Verdict:    Accepted
* Date:        2015/09/22                                             
*
* Coder:      Md. Shahidul Islam
* Dept. :     Computer Science and Engineering
* Institute:  Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
vi Graph[10002];
int erdos[10002];
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    erdos[start]=0; // Erdos number of Erdos, P. is 0
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            int v=Graph[u][i];
            if(erdos[v]==INF)  // not visited yet
            {
                erdos[v]=erdos[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
   //fast;
   //in;
   //out;
   char str[10002], temp[1000], temp1[1000];
   int test, cas, i, j, k, P, N, m, len, n, g, person[1002], per;
   bool stop;
   string name, name1, name2;
   map<string, int> id;
   scanf("%d", &test);
   for(cas=1;cas<=test;cas++)
   {
       scanf("%d %d", &P, &N);
       getchar();
       id["Erdos,P."]=0;    // mapped id of Erdos, P. is 0
       m=1;
       for(g=0;g<P;g++)
       {
           gets(str);
           len=strlen(str);
           k=per=0;
           stop=false;
           while(!stop) // until all names taken
           {
               for(n=0;k<=len && !stop;k++) // find first name
               {
                   while(str[k]==' ') k++; // ignore whitespace
                   if(str[k]==',' || str[k]==':' || str[k]=='\0') // first name finished
                   {
                        if(str[k]==':' || str[k]=='\0')
                        {
                            stop=true;
                            break;
                        }
                        temp[n++]=',';
                        temp[n]='\0';
                        name1=string(temp);
                        n=0;
                        k++;
                        while(str[k]==' ') k++;     // ignore whitespace
                        for(;k<=len && !stop;k++)   // now find last name
                        {
                            if(str[k]==',' || str[k]==':' || str[k]=='\0') //because, last name finished with , or :
                               {
                                   temp[n]='\0';
                                   n=0;
                                   name2=string(temp);
                                   name=name1+name2;          // combine first name and last name
                                   //cout<<name<< "\n";
                                   if(id.find(name)==id.end())
                                        id[name]=m++;
                                    //printf("%d\n", id[name]);
                                   person[per++]=id[name]; // save scanned named id
                                   
                                   
                                   if(str[k]==':' || str[k]=='\0')
                                   {
                                        //printf("%d\n.....\n", per);
                                       //for(i=0;i<per;i++)
                                         //  printf("%d ", person[i]);
                                        //printf("\n");
                                       for(i=0;i<per;i++)    // make graph with all found names
                                       {
                                           for(j=0;j<per;j++)
                                           {
                                               if(i!=j)
                                               {
                                                   Graph[person[i]].push_back(person[j]); // graph with mapped id
                                               }
                                            }
                                        }
                                        stop=true;
                                        break;
                                    }
                                    else
                                    {
                                        k++;
                                        break;
                                    }               //last name finished
                               }
                               else if(str[k]!=' ') temp[n++]=str[k];  // continue making first name
                            }
                       
                       }
                       else if(str[k]!=' ')temp[n++]=str[k]; // continue making first name
               }
           }
       }
       for(i=1;i<=m;i++)
            erdos[i]=INF;  // initialize all with infinity
        bfs(0);
        cout<< "Scenario" << " " << cas<< "\n";
        for(i=1;i<=N;i++)
        {
            scanf("%s %s", temp, temp1);
            name1=string(temp);
            name2=string(temp1);
            name=name1+name2;
            cout<<temp<< " " <<temp1<< " ";
            if(id.find(name)==id.end())
                cout<< "infinity" << "\n";
            else if(erdos[id[name]]==INF)
                cout<< "infinity" << "\n";
            else cout<<erdos[id[name]] << "\n";
        }
        id.clear();
        for(i=0;i<=m;i++)
            Graph[i].resize(0);
   }
   return 0;
}
