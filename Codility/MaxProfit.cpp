int solution(vector<int> &a) {
    int n = a.size();
    if (n==0) return 0;
    int minSoFar = a[0], mxProfit = 0;
    for(int i=1;i<n;i++){
        mxProfit = max(mxProfit, a[i]-minSoFar);
        minSoFar = min(minSoFar, a[i]);
    }
    return mxProfit;
}
