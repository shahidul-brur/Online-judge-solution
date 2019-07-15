class Solution {
public:
    int par[105], siz[105];
    int who(int u){
        if(par[u]==u) return u;
        return par[u] = who(par[u]);
    }
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(), logs.end());
        for(int i=0;i<N;i++) par[i] = i, siz[i]  = 1;
        for(int i = 0;i<logs.size();i++){
            int tim = logs[i][0], u = logs[i][1], v = logs[i][2];
            u = who(u), v = who(v);
            if(u==v) continue;
            siz[u]+=siz[v];
            if(siz[u]==N) return tim;
            par[v] = u;
        }
        return -1;
    }
};
