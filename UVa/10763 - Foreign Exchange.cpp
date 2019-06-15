#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(const int& num1, const int& num2) {
            return num1 > num2;
        }
int main()
{
    freopen("10763.txt", "r", stdin);
    unsigned long long int n,match,i,j;
    vector<unsigned long long int> from(500005), to(500005);
    while(scanf("%llu",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%llu %llu",&from.at(i),&to.at(i));
        }

        sort(from.begin(), from.end(),comp);
        sort(to.begin(), to.end(),comp);
        match=1;
        for(i=0;i<n;i++)
        {
            if(from.at(i)!=to.at(i))
            {
                match=0;
                break;
            }

        }

        if(match==1)
            printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
