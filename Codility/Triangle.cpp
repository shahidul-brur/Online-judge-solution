#include <algorithm>
int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    for(int i = 0;i<(int)A.size()-2;i++){
        if ((long)A[i]+(long)A[i+1]>A[i+2]) return 1;
    }
    return 0;
}
