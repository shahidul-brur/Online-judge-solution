int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int cnt = 0;
    for(int i=0;i<(int)A.size();i++){
        if (i-1>=0 && A[i]==A[i-1]) continue;
        ++cnt;
    }
    return cnt;
}

// 2
int solution(vector<int> &A) {
    bool exist[2000002] = {false};
    int n = A.size(), cnt = 0;
    for(int i=0;i<n;i++) exist[A[i]+1000000]=1;
    for(int i=0;i<=2000000;i++) cnt+=exist[i];
    return cnt;
}
