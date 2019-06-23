#include<bits/stdc++.h>
using namespace std;
const int MX = 200005;
vector<pair <int, int> >seg;
int main()
{
    int n, x, y;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>x>>y;
        seg.push_back(make_pair(x, 1));
        seg.push_back(make_pair(y+1, -1));
    }
    sort(seg.begin(), seg.end());
    int cur = 0;
    int s = seg.size();
    for(int i = 0;i<s;i++)
    {
        cur+=seg[i].second;
        if(cur>2)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
