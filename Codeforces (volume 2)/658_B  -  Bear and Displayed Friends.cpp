#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    vector<int> v;
    int n, k, q, i, t[150005], type, id;
    while(cin>>n>>k>>q)
    {
        for(i=1;i<=n;i++)
            cin>>t[i];
        for(i=1;i<=q;i++)
        {
            cin>>type>>id;
            if(type==1)
            {
                v.insert(upper_bound(v.begin(), v.end(), t[id]), t[id]);
            }
            else 
            {
                if(!binary_search(v.begin(), v.end(), t[id]))
                    cout << "NO\n";
                else
                {
                    int p = upper_bound(v.begin(), v.end(), t[id]) - v.begin();
                    
                   // cout << p << " ";
                    
                    if(v.size()-p+1<=k)
                        cout << "YES\n";
                    else cout << "NO\n";
                }
            }
            /*
            for(int j=0;j<v.size();j++)
            {
                cout << v[j] << " ";
            }
            cout << "\n";
            */
        }
        v.clear();
    }
    return 0;
}
