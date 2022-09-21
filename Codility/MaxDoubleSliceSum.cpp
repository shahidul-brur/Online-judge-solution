/**
   mistakes I made:
      1. if n==3, return max(0,A[1]); WA, since exactly 3 indices will be excluded
      2. running 2nd loop upto > 1, instead of > 0; WA, since index 1 never being excluded, which may be best choice
      3. calculating mx, after calculating mx_ending_here in the second loop
      4. not assigning 0 to lft[0]
**/

#include <algorithm>
int solution(vector<int> &A) {
    int n = A.size();
    int lft[n];
    int mx_ending_here = 0;
    lft[0] = 0;
    for (int i=1;i<n-1;i++){
        mx_ending_here = max(A[i], mx_ending_here+A[i]);
        mx_ending_here = max(mx_ending_here, 0);
        lft[i]=mx_ending_here;
    }
    mx_ending_here = 0;
    int mx = 0;
    for (int i=n-2;i>0;i--){
        mx = max(mx_ending_here + lft[i-1], mx);
        mx_ending_here = max(A[i], mx_ending_here+A[i]);
        mx_ending_here = max(mx_ending_here, 0);
    }
    return mx;
}