//Accepted

#include<bits/stdc++.h>
using namespace std;
struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l > r;
  }
};
int main()
{
    freopen("10954.txt", "r", stdin);
    int n, num,i,a, b, sum, total;
    priority_queue<int,vector<int>, compare > q;
    while(scanf("%lld",&n) && n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            q.push(num);
        }
        total=0;
        while(q.size()>1)
        {
            a=q.top();
            q.pop();

            b=q.top();
            q.pop();

            sum=a+b;
            total+=sum;
            q.push(sum);
        }
        q.pop();
        cout<<total<< '\n';
    }
    return 0;
}
