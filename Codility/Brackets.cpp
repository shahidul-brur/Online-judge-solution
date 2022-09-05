#include <stack>

int solution(string &s) {
    stack<char> stk;
    int n = (int)s.size();
    for(int i=0;i<n;i++){
        if(s[i]==')' && (stk.empty() || stk.top()!='(')) return 0;
        if(s[i]==']' && (stk.empty() || stk.top()!='[')) return 0;
        if(s[i]=='}' && (stk.empty() || stk.top()!='{')) return 0;
        if(s[i]==')' || s[i]==']' || s[i]=='}') stk.pop();
        else stk.push((char)s[i]);
    }
    return stk.empty();
}
