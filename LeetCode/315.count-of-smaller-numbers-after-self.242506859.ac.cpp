/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
class Solution {
public:
    vector<int> cnt;
    int n;
    void add(int pos, int val){
        while(pos<=n) cnt[pos]+=val, pos+=pos&-pos;
    }
    int smaller(int pos){
        int tot = 0;
        while(pos>0) tot+=cnt[pos], pos-=pos&-pos;
        return tot;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        cnt.resize(n+1);
        vector<pair<int,int>> sorted;
        for(int i = 0;i<n;i++){
            sorted.push_back(make_pair(nums[i], i));
        }
        sort(sorted.begin(), sorted.end());
        int last = 1;
        for(int i = 0;i<n;i++){
            if(i>0 && sorted[i].first>sorted[i-1].first) last++;
            nums[sorted[i].second] = last;
        }
        fill(cnt.begin(), cnt.end(), 0);
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            ans.push_back(smaller(nums[i]-1));
            add(nums[i], +1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


