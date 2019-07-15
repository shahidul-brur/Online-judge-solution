
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        int lft[n], rgt[n];
        lft[0] = -1;
        rgt[n-1] = n;
        for(int i = 1;i<n;i++){
            int pos = i-1;
            while(pos>=0 && a[pos]>=a[i]) pos = lft[pos];
            lft[i] = pos;
        }
       
        for(int i = n-2;i>=0;i--){
            int pos = i+1;
            while(pos<=n-1 && a[pos]>=a[i]) pos = rgt[pos];
            rgt[i] = pos;
        }
        int mx = 0;
        for(int i = 0;i<n;i++)
            mx = max(mx, (rgt[i]-lft[i]-1)*a[i]);
        return mx;
    }
};
