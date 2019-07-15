/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &A) {
        int lo = -1, hi = A.length();
        while (hi - lo > 1){
            int mid = (hi + lo)>>1;
            if (A.get(mid) > A.get(mid + 1)) 
                 hi = mid;
            else 
                 lo = mid; 
        }
        return lo;
    }
};
