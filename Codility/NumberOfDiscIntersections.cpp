// you can use includes, for example:
#include <algorithm>
#include <limits.h>


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &a) {
    int n = a.size();
    if (n==0) return 0;
    vector<int> lft, rgt;
    for(int i=0;i<n;i++){
        lft.push_back(i-a[i]);
        if (a[i]>INT_MAX-i){
            rgt.push_back(INT_MAX);
        }
        else {
            rgt.push_back(a[i]+i);
        }
    }
    sort(lft.begin(), lft.end());
    sort(rgt.begin(), rgt.end());
    int startIdx = 0, endIdx = 0, opened = 0;
    int cnt = 0;
    while (startIdx<n) {
        if (lft[startIdx] <= rgt[endIdx]){
            cnt+=opened;
            startIdx++;
            opened++;
            if (cnt > 10000000) return -1;
        }
        else{
            opened--;
            endIdx++;
        }
    }
    return cnt;
}
