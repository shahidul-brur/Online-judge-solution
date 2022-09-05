int solution(vector<int> &A) {
    int n=(int)A.size();
    int cnt[n+1] = {0};
    for(int i=0;i<n;i++) if(A[i]>=1 && A[i]<=n) cnt[A[i]]++;
    for(int i=1;i<=n;i++) if (cnt[i]!=1) return 0;
    return 1;
}
