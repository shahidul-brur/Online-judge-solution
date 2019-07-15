class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(), v.end());
        for(int i=0;i<n-1;i++){
            int pos = lower_bound(v.begin()+i+1, v.end(), make_pair(target-v[i].first,-1)) - v.begin();
            if(pos<n && v[pos].first+v[i].first==target){
                
                return vector<int>({min(v[i].second,v[pos].second), max(v[i].second,v[pos].second)});
            }
        }
        return vector<int>();
    }
};
