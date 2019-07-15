class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if(clips.size()==0) return -1;
        sort(clips.begin(), clips.end(), cmp);
        if(clips[0][0]!=0) return -1;
        int last = 0, cnt = 0;
        for(int i=0;i<clips.size();i++){
            if(clips[i][0]>last) return -1;
            cnt++;
            int mx = clips[i][1];
            
            while(i+1<clips.size() && clips[i+1][0]<=last){
                mx = max(mx, clips[i+1][1]);
                i++;
            }
            last = mx;
            if(last>=T) return cnt;
        }
        return -1;
    }
    static bool cmp(vector<int> a, vector<int> b)
    {
        return (a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]));
    }
};
