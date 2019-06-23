#include<bits/stdc++.h>
using namespace std;
struct t
{
    int score[10];
    char c[10][20];
};
struct t reg[100005];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m, i, j, r, sc;
    char name[20];
    while(cin>>n>>m)
    {
        for(i=1;i<=m;i++)
        {
            for(j=0;j<5;j++)
            {
                reg[i].score[j] = -1;
                strcpy(reg[i].c[j], "none");
            }
        }
        for(i=1;i<=n;i++)
        {
            cin>>name>>r>>sc;
            
            if(sc>reg[r].score[0])
            {
                reg[r].score[2] = reg[r].score[1];
                strcpy(reg[r].c[2], reg[r].c[1]);
                
                reg[r].score[1] = reg[r].score[0];
                strcpy(reg[r].c[1], reg[r].c[0]);
                
                reg[r].score[0] = sc;
                strcpy(reg[r].c[0], name);
            }
            else if(sc>reg[r].score[1])
            {
                reg[r].score[2] = reg[r].score[1];
                strcpy(reg[r].c[2], reg[r].c[1]);
                
                reg[r].score[1] = sc;
                strcpy(reg[r].c[1], name);
            }
            else if(sc>reg[r].score[2])
            {
                reg[r].score[2] = sc;
                strcpy(reg[r].c[2], name);
            }
        }
        
        for(i=1;i<=m;i++)
        {
            if(reg[i].score[1] == reg[i].score[2])
                cout << "?\n";
            else
            {
                cout<< reg[i].c[0] << " " << reg[i].c[1] << "\n";
            }
        }
    }
    return 0;
}