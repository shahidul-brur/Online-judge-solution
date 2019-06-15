/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
struct Node
{
    //string name;
    char name[205];
    Node *left, *right;
};
Node* makeTree(Node* root, char *s)
{
    if(root==NULL)
    {
        root=new Node();
        strcpy(root->name,s);
        root->left = root->right = NULL;
    }
    else if(strcmp(s, root->name)==0);
    else if(strcmp(s, root->name)<0)
    {
        root->left=makeTree(root->left, s);
    }
    else if(strcmp(s, root->name)>0)
    {
        root->right=makeTree(root->right, s);
    }
    return root;
}
void printTree(Node* root)
{
    if(root==NULL)
        return;
    printTree(root ->left);
    cout<<root->name<<endl;
    printTree(root ->right);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    Node* root=NULL;
    int len, i, j,c=0, len1;
    string txt, tmp;
    char temp[202];
    vector<string> word;
    while(cin>>txt)
    {
        len=txt.size();
        for(i=0,j=0;i<=len;i++)
        {
            if(txt[i]>='A' && txt[i]<='Z')
                temp[j++]=txt[i]-'A'+'a';
            else if(txt[i]>='a' && txt[i]<='z')
                temp[j++]=txt[i];
            else
            {
                temp[j]='\0';
                j=0;
                len1=strlen(temp);
                if(len1>0)
                {
                    root=makeTree(root, temp);
                }

            }
        }
    }
    printTree(root);
    return 0;
}
/**********************************************************
About this problem:

************************************************************/


