int solution(vector<int> &A) {
    if (A.size() == 0) return -1;
    int stackLen = 1, stackTop = 0;
    int n = A.size();
    for(int i=1;i<n;i++){
        if (stackLen == 0 || A[i] == A[stackTop]){
            stackLen++;
            stackTop = i;
        }
        else {
            stackLen--;
        }
    }
    if (stackLen == 0) return -1;
    int cnt = 0;
    for(int i=0;i<n;i++) if(A[i]==A[stackTop])
        cnt++;
    if (cnt > n/2) {
        //cout << stackTop << "\n";
        return stackTop;
    }
    return -1;
}
