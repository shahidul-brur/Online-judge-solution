int solution(vector<int> &A) {
    int n = A.size();
    if (n==0) return 0;
    int stackSize = 1, stackTop = A[0];
    for(int i=1;i<n;i++){
        if (stackSize==0 || A[i]==stackTop){
            stackTop = A[i];
            stackSize++;
        }
        else {
            stackSize--;
        }
    }
    if (stackSize==0)
        return 0;
    int cnt = 0, res = 0;
    for(int i = 0;i<n;i++){
        if (A[i]==stackTop){
            cnt++;
        }
    }
    int cur = 0;
    for(int i = 0;i<n;i++){
        if (A[i]==stackTop){
            cur++;
        }
        if (cur>(i+1)/2 && cnt-cur>(n-i-1)/2)
            res++;
    }
    return res;
}
