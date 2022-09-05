int solution(string &s) {
    int cnt = 0;
    int n = s.size();
    if (n==0) return 1;
    for(int i=0;i<n;i++){
        if (s[i]=='(') cnt++;
        else cnt--;
        if (cnt<0) return 0;
    }
    if (cnt==0) return 1;
    return 0;
}
