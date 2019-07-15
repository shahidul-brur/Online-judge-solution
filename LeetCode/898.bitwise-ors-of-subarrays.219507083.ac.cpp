
class Solution {
public:
    int subarrayBitwiseORs(vector<int> A) {
        unordered_set<int> res, cur, cur2;
        
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            cur = cur2;
            for (int j: cur) res.insert(j);
        }
        return res.size();
    }
};
