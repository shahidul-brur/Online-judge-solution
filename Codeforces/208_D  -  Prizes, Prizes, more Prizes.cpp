/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<iostream>
using namespace std;
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, score[51], point, cnt[6];
    long long prize[6];
    while(cin>>n)
    {
        f(i, 1, n) cin>>score[i];
        f(i, 1, 5) cin>>prize[i], cnt[i] = 0LL;
        
        point = 0;
        f(i, 1, n)
        {
            point+=score[i];
            F(j, 5, 1)
            {
                if(prize[j]<=point)
                {
                    cnt[j]+=point/prize[j];
                    point%=prize[j];
                }
            }
        }
        f(i, 1, 5)
        {
            if(i>1)
                cout << " ";
            cout << cnt[i];
        }
        cout << "\n" << point << "\n";
    }
    return 0;
}

