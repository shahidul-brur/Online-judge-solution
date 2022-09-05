int solution(vector<int> &A) {
    int n = (int)A.size();
    int res = 0;
    for(int i=0;i<n;i++) res ^= A[i];
    return res;
}
