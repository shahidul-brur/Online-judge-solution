class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        bool valid = 1;
        stack<char> stk;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i] =='{' || s[i] == '[') stk.push(s[i]);
            else{
                if(stk.empty() || (s[i]==')'&&stk.top()!='(') || (s[i]=='}'&&stk.top()!='{') || (s[i]==']'&&stk.top()!='[')){
                    valid = 0;
                    break;
                }
                stk.pop();
            }
        }
        if(!stk.empty()) valid = 0;
        return valid;
    }
};
