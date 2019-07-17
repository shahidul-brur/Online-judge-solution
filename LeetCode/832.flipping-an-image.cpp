class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        if(n==0) return A;
        int m = A[0].size();
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i].resize(m);
            for(int j = 0;j<m;j++) ans[i][m-1-j] = 1-A[i][j];
        }
        return ans;
    }
};
