class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] ans = new int[A.length];
        int n=A.length, j=0;
        for(int i=0;i<n;i++) if(A[i]%2==0) ans[j++] = A[i];
        for(int i=0;i<n;i++) if(A[i]%2==1) ans[j++] = A[i];
        return ans;
    }
}
