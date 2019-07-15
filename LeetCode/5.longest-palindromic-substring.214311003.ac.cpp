class Solution {
public:
    int P[2][1005]; // P[0][i] -> even length palindrome centered at i
                // P[1][i] ->  odd length palindrome centered at i
string manacer(string s){
    if(s.size()==0) return s;
    int n = (int) s.length(), mx = 0, idx, l, r;
    for(int cas = 0;cas<=1;cas++){
        l = r = -1;
        for (int i = 0; i < n; i++) {
            int cur = cas;
            if (i < r)
                cur = min(r - i + 1, P[cas][l + r - i+(cas==0)]);
            while (i + cur < n && i - cur - (cas==0)>= 0 && s[i-cur-(cas==0)] == s[i + cur])
                cur++;
            P[cas][i] = cur;
            int len = 2*cur-cas;
            if(len>mx){
                mx = len;
                idx = i - cur + cas;
            }
            if (i + cur - 1 > r) {
                l = i - cur + cas; 
                r = i + cur - 1;
            }
        }
    }
    return s.substr(idx,mx);
}
    string longestPalindrome(string s) {
        return manacer(s);
    }
};
