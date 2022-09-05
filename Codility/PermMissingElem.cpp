/**
    mistakes: not diving by 2, not typecasting A.size()
    careful: is long long needed
*/
int solution(vector<int> &A) {
    long long sum = 0LL;
    for(int i=0;i<(int)A.size();i++) sum+=A[i];

    return ((int)A.size()+1)*1LL*((int)A.size()+2)/2 - sum;
}

