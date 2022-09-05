vector<int> solution(int N, vector<int> &A) {
    int len = A.size();
    vector<int> counterVal(N,0);
    int mx=0, mxPos=-1, maxAssign = 0;
    for (int i=0;i<lastMaxOp;i++) {
        int counterNumber = A[i]-1;
        if(counterNumber<N) {
            if (counterVal[counterNumber] < maxAssign){
                counterVal[counterNumber] = maxAssign;
            }
            counterVal[counterNumber]++;
            mx = max(mx, counterVal[counterNumber]);
        }
        else {
            mxPos = i;
            maxAssign = mx;
        }
    }
    for (int i=0;i<N;i++) {
        if (counterVal[i] < maxAssign)
            counterVal[i] = maxAssign;
    }
    return counterVal;
}

