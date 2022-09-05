int solution(vector<int> &A) {
    int n = (int)A.size();
    int end = n;
    for(int i=n-1;i>=0;i--){
        if(A[i]<=0 || A[i]>n) {
            --end;
            swap(A[i], A[end]);
        }
    }
    for(int i=0;i<end;i++){
        int val = abs(A[i]);
        if (val>=1 && val<=end)
            A[val-1] = -abs(A[val-1]);
    }
    for(int i=0;i<end;i++){
        if(A[i]>0) return i+1;
    }
    return end+1;
}
