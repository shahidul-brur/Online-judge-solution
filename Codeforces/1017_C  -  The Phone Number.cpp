#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int LIS(vector<int> a)
{
    int n = a.size();
    vector<int> d;
    for(int i = 0;i<n;i++)
    {
        int x = a[i];
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}

int LDS(vector<int> a)
{
    reverse(a.begin(), a.end());
    int n = a.size();
    vector<int> d;
    for(int i = 0;i<n;i++)
    {
        int x = a[i];
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
//        vector<int> v;
//        for(int i=1;i<=n;i++)
//        {
//            v.push_back(i);
//        }
//        int mini = INT_MAX;
//        vector<int> co;
//        do{
//            int in = LIS(v);
//            int dec = LDS(v);
//            if(in+dec<mini)
//            {
//                mini  = in+dec;
//                co.clear();
//                for(int i=0;i<n;i++) co.push_back(v[i]);
//            }
//        }
//        while(next_permutation(v.begin(), v.end()));
//        cout << mini << "\n";
//        for(int i = 0;i<n;i++) cout << co[i] << " ";
        int root = sqrt(n);
        for(int i = 1;i<=n;i+=root) 
        {
            for(int j=min(n, i+root-1);j>=i;j--)
                ans.push_back(j);
        }
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        ans.clear();
    }
    return 0;
}

