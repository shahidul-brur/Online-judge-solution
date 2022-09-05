
// mistakes:
// initializing lo with sum and abs(sum)
int solution(vector<int> &a) {
    // write your code in C++14 (g++ 6.2.0)
    int n = (int)a.size();
    int s = 0;
    for(int i=0;i<n;i++) {
        s+=a[i];
    }
    int lo = (int)(1e9);
    int cur = 0;
    for (int i=0;i<n-1;i++){
        cur+=a[i];
        lo=min(lo, abs(cur- (s-cur)));
    }
    return lo;
}
