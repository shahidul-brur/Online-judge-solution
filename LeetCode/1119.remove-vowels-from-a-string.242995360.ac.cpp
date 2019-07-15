class Solution {
public:
    string removeVowels(string s) {
        string t;
        set<char> ch = {'a','e','i','o','u'};
        for(char c:s) if(ch.count(c)==0) t+=c;
        return t;
    }
};
