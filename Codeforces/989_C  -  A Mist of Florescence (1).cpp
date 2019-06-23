#include<bits/stdc++.h>
using namespace std;
char s[32][51];
void init(char ch, int amount, int r, int c, int inc)
{
    for(int i = r;i<50&&amount>0;i+=inc) for(int j = c;j<50&&amount>0;j+=inc)
        s[i][j] = ch, --amount;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    int a[4];
    for(int i=0;i<32;i++) s[i][50] = '\0';
    for(int i=0;i<4;i++) cin>>a[i], init('A'+i, 8*50, i*8, 0, 1);
    char ch[] = {'B', 'C', 'D', 'A'};
    for(int i=0;i<4;i++) init(ch[i], a[ch[i]-'A']-1, i*8, 0, 2);
    cout << "32 50" << endl;
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<50;j++) cout << s[i][j];
        cout << endl;
    }
    return 0;
}
