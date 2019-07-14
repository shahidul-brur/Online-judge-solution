class Solution {
public:
    int dp[(1<<16)+2][62], n, r, msk[62];
    const int INF = 100;
    map<string, int> id;
    int cal(int mask, int pos, vector<vector<string>>& people){
        if(mask==(1<<r)-1) return 0;
        if(pos==n) return INF;
        int &ret = dp[mask][pos];
        if(ret!=-1) return ret;
        int nile = 1 + cal(mask|msk[pos], pos+1, people);
        int na_nile = cal(mask, pos+1, people);
        ret = min(nile, na_nile);
        return ret;
    }
    vector<int> ans;
    void choose(int mask, int pos, vector<vector<string>>& people){
        if(pos==n || mask==(1<<r)-1) return;
        int nile = 1 + cal(mask|msk[pos], pos+1, people);
        int na_nile = cal(mask, pos+1, people);
        if(nile<na_nile){
            ans.push_back(pos);
            choose(mask|msk[pos], pos+1, people);
        }
        else choose(mask, pos+1, people);
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        memset(dp, -1, sizeof(dp));
        n = people.size();
        r = req.size();
        for(int i=0;i<r;i++) id[req[i]] = i;
        for(int pos=0;pos<n;pos++){
            msk[pos] = 0;
            for(string s:people[pos]){
                msk[pos]|=1<<id[s];
            }
        }
        cal(0,0,people);
        choose(0,0,people);
        return ans;
    }
};
