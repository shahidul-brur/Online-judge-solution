vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int n = S.size();
    int cnt[4][n+1] = {0};
    string txt = "ACGT";
    for(int i=0;i<n;i++){
        for (int ch = 0;ch<4;ch++){
            cnt[ch][i+1]=cnt[ch][i];
            if(txt[ch]==S[i]) cnt[ch][i+1]++;
        }
    }
    int k = (int)P.size();
    vector<int> res;
    for(int i=0;i<k;i++){
        for (int ch = 0;ch<4;ch++){
            if (cnt[ch][Q[i]+1]-cnt[ch][P[i]]>0){
                res.push_back(ch+1);
                break;
            }
        }
    }
    return res;
}
