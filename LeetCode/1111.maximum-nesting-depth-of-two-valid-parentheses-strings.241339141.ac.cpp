class Solution {
public:
    
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int d[n];
        vector<int> ans(n,0);
        stack<int> stk;
        stk.push(0);
        int mx = 0;
        for(int i=0;i<n;i++){
            char c = seq[i];
            if(c=='('){
                d[i]=stk.top()+1;
                stk.push(d[i]);
                }
            else {
                d[i] = stk.top();
                stk.pop();
                }
            mx = max(d[i], mx);
        }
        int h = mx/2;
        for(int i=0;i<n;i++) if(d[i]>h) ans[i]=1;
        return ans;
    }
};
