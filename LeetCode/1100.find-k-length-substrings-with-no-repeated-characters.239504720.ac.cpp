class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int cnt[26]; memset(cnt, 0, sizeof(cnt));
        int n = S.length();
        int lft = 0, ans = 0;
        cnt[S[0]-'a']++;
        if(K==1) ans = 1;
        for(int i = 1;i<n;i++){
            cnt[S[i]-'a']++;
            while(cnt[S[i]-'a']>1){
                cnt[S[lft] - 'a']--;
                lft++;
            }
            if(i-lft+1>=K){ ans+=1;//i-lft+1 - (K-1);
            //cout << i << ": " << i-lft+1 - (K-1) << "\n";
                          }
        }
        return ans;
    }
};
