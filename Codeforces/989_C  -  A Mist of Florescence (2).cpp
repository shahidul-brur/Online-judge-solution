#include<bits/stdc++.h>
using namespace std;
#define f0(i,b) for(int i=0;i<(b);i++)
char s[55][55];
void init(char ch, int amount, int r, int c, int inc)
{
    for(int i = r;i<50&&amount>0;i+=inc) for(int j = c;j<50&&amount>0;j+=inc)
        s[i][j] = ch, --amount;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int a[5];
    f0(i,4) cin>>a[i], init('A'+i, 12*50, i*12, 0, 1);
    char ch[] = {'B', 'C', 'D', 'A'};
    f0(i,4) init(ch[i], a[ch[i]-'A']-1, i*12, 0, 2);
    cout << "48 50" << endl;
    f0(i,48)
    {
        f0(j,50) cout << s[i][j];
        cout << endl;
    }
    return 0;
}
