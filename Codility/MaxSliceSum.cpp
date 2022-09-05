int solution(vector<int> &A) {
    int mx = A[0], mxEndingHere = A[0];
    int n = A.size();
    for (int i=1;i<n;i++){
        mxEndingHere = max(A[i], mxEndingHere+A[i]);
        mx = max(mx, mxEndingHere);
    }
    return mx;
}
