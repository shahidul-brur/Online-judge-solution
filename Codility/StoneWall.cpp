#include <stack>

int solution(vector<int> &h) {
    stack<int> stk;
    int n = h.size(), cnt = 0;
    for(int i=0;i<n;i++){
        while(!stk.empty() && stk.top() > h[i]) {
            stk.pop();
            cnt++;
        }
        if (stk.empty() || h[i]>stk.top()) stk.push(h[i]);
    }
    cnt += (int)stk.size();
    return cnt;
}
