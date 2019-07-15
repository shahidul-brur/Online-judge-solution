class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v;
        for(int x:A)
            v.push_back(x*x);
        sort(v.begin(), v.end());
        return v;
    }
};
