#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, total, j;
    while(cin>>n)
    {
        int s=0;
        for(i=5;;i*=2)
        {
            s=s+i;
            if(n<=s)
            {
                s = s-i;
                int k=i/5;
                if(k*1 + s >=n)
                    cout << "Sheldon\n";
                else if(k*2 + s >=n)
                    cout << "Leonard\n";
                else if(k*3 + s >=n)
                    cout << "Penny\n";
                else if(k*4 + s >=n)
                    cout << "Rajesh\n";
                else 
                    cout << "Howard\n";
                break;
            }
        }
    }
    return 0;
}