class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int cur = capacity;
        int beg[1005], fin[1005];
        memset(beg, 0, sizeof(beg));
        memset(fin, 0, sizeof(fin));
        for (auto x:trips){
            beg[x[1]]+=x[0];
            fin[x[2]]+=x[0];
        }
        for(int i=0;i<=1002;i++){
            cur+=fin[i];
            cur-=beg[i];
            if(cur<0) return false;
        }
        return true;
    }
};
