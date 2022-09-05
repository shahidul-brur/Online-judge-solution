/**
 mistakes: not returning -1 when cnt > 1e9
*/
int solution(vector<int> &A) {
    int east = 0; 
    long long cnt = 0;
    for(int i=0;i<(int)A.size();i++){
        if(!A[i]) east++;
        else cnt+=east;
        if (cnt>(int)1e9){
            cnt = -1;
            break;
        }
    }
    return (int)cnt;
}
>
