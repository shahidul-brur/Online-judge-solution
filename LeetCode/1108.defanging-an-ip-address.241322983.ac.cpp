class Solution {
public:
    string defangIPaddr(string a) {
        string res;
      for(char c:a) if(c=='.') res+="[.]"; else res+=c; return res;
    }
};
