class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int s = arr.size(), z=0;
        vector<int> a;
        for(int i=0;i<s;i++){
            if(arr[i]==0){
                a.push_back(0);
                if(a.size()<s) a.push_back(0);
            }
            else a.push_back(arr[i]);
            if(a.size()==s) break;
        }
        arr = a;
    }
};
