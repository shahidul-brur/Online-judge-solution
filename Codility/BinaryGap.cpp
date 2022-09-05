int solution(int N) {
    int mx_gap = 0;
    while(N>0) {
        int one = 0;
        while(N&1) {
            N>>=1, one = 1;
        }
        int cnt = 0;
        while (N> 0 && (N&1)==0) {
            cnt++;
            N>>=1;
        }
        if (one!= 0 && N&1) {
            mx_gap = max(mx_gap, cnt);
        }
    }
    return mx_gap;
}
