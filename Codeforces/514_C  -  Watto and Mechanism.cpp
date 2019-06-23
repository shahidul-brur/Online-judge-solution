#include <bits/stdc++.h>
using namespace std;
const int MX = 600002;
int n, m, siz;
string s;
struct trie{
    int ch[3];
    bool isEnd;
}node[MX];
void push(){
    int cur = 1;
    int len = s.length();
    for(int i = 0;i<len;i++){
        int c = s[i] - 'a';
        if(node[cur].ch[c]==0){
            node[cur].ch[c] = ++siz;
        }
        cur = node[cur].ch[c];
    }
    node[cur].isEnd = true;
}

bool searchWord(int cur, int pos, int diff){
    if(s[pos]=='\0'){
        if(node[cur].isEnd==1 && diff==1){
            
            return true;
        }
        return false;
    }
    for(int i = 0;i<3;i++){
        if(node[cur].ch[i]==0) continue;
        bool f = false;
        if(diff==1){
            if(i==s[pos]-'a')
                f = searchWord(node[cur].ch[i], pos+1, diff);
            else continue;
        }
        else {
            if(i==s[pos] - 'a')
                f = searchWord(node[cur].ch[i], pos+1, 0);
            else f = searchWord(node[cur].ch[i], pos+1, 1);
        }
        if(f){
            //cout << pos << "  " << i << ": ";
            return true;
        }
    }
    return false;
}
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    siz = 1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        push();
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        bool found = searchWord(1, 0, 0);
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

