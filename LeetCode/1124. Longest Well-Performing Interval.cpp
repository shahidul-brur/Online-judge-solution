class Solution {
public:
    int longestWPI(vector<int>& arr) {
        int n=arr.size(),i;
        map<int, int> prevSum; 
        int maxlen = 0, sum=0;  
        int currlen; 

        for (i = 0; i < n; i++) { 

            if (arr[i] > 8) 
                sum++; 
            else
                sum--; 
            if (sum > 0) { 
                maxlen = i + 1; 
            } 
            else if (sum <= 0) { 
                if (prevSum.find(sum - 1) != prevSum.end()) { 
                    currlen = i - prevSum[sum - 1]; 
                    maxlen = max(maxlen, currlen); 
                } 
            }
            if (prevSum.find(sum) == prevSum.end()) 
                prevSum[sum] = i; 
        } 

        return maxlen; 
    }
};