class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        set<int> s,ds;
        int n = nums.size();
        int cnt[100002],mx=0;
        memset(cnt, 0, sizeof(cnt));
        for(int x:nums){
            cnt[x]++;
            mx = max(cnt[x], mx);
             s.insert(x);
            /*
            if(cnt[x]==2) ds.insert(x);
            */
        }
        if(s.size()<k) return 0;
        /*
        while(ds.size()>0){
            int need = k-
        }
        */
        if(k*mx>n) return 0;
        return 1;
    }
};
