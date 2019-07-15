class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int n = A.size();
        int mx = -1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) if(A[i]+A[j]<K)
                mx = max(mx, A[i]+A[j]);
        }
        return mx;
    }
};
