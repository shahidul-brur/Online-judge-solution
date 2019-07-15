class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> v;
        for(int i=0;i<queries.size();i++){
            /*string s;
            for(char c:queries[i]) if(c>='A' && c<='Z') s+=c;
            bool cur = (s==p);
            */
            v.push_back(isSub(queries[i],pattern));
        }
        return v;
    }
    bool isSub(string &s, string &sub){
        string up_sub, up_s;
        for(char c:sub) if(isupper(c)) up_sub+=c;
        for(char c:s) if(isupper(c)) up_s+=c;
        if(up_sub!=up_s) return false;
        int j=0, i=0;
        for(;i<s.size();i++){
            if(s[i]==sub[j]){
                j++;
            }
            if(j==sub.size()) return true;
        }
        return false;
    }  
};
