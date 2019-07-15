class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool ch[52] = {};
        int j = J.size(), s = S.size();
        for(int i=0;i<j;i++) 
            if(isupper(J[i]))
                ch[J[i]-'A'+26] = 1;
            else ch[J[i]-'a'] = 1;
        int cnt = 0;
        for(int i=0;i<s;i++)
            if(isupper(S[i]) && ch[S[i]-'A'+26])
                cnt++;
            else if(islower(S[i]) && ch[S[i]-'a'])
                cnt++;
        return cnt;
    }
};
