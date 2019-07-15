#define f0(i,b) for(int i=0;i<(b);i++)
class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.size();
        string ans;
        stack<int> stk;
        f0(i,n)
        {
            if(S[i]=='(') stk.push(i);
            else {
                if(stk.size()==1) for(int j=stk.top()+1;j<i;j++) ans+=S[j];
                stk.pop();
            }
        }
        return ans;
    }
};
