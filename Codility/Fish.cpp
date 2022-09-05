
#include <stack>
int solution(vector<int> &A, vector<int> &B) {
    stack<int> stk;
    int n = A.size();
    if (n==0) return 0;
    for(int i=0;i<n;i++){
        if (B[i] == 1 || stk.empty() || B[stk.top()]==0){
            stk.push(i);
        }
        else {
            while (stk.size() > 0 && B[stk.top()]==1 && A[stk.top()] < A[i]){
                stk.pop();
            }
        
            if (stk.empty() || B[stk.top()]==0 || A[i] > A[stk.top()]){
                stk.push(i);
            }
        }
    }
    return (int)stk.size();
}
