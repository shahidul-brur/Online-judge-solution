class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0, n = A.size();
        vector<bool> v;
        for(int i=0;i<n;i++)
        {
            num = (num*2 + A[i])%5;
            if(num==0) v.push_back(1);
            else v.push_back(0);
        }
        return v;
    }
};
