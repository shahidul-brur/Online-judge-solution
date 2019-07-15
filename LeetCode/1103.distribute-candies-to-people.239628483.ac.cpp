class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        vector<int> ans(n,0);
        int i = 0, cur = 1;
        while(1){
            if(c<=cur){
                ans[i]+=c;
                break;
            }
            else{
                ans[i]+=cur;
                c-=cur;
                i++;
                cur++;
                if(i==n) i=0;
            }
        }
        return ans;
        
    }
};
