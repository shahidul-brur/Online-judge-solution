#include<bits/stdc++.h>
using namespace std;
const int MX = 10002;

struct tupple{
    int r[2];
    int index;
    bool operator<(const tupple &t)const{
        return (r[0]<t.r[0] || (r[0] == t.r[0] && r[1] < t.r[1]));
    }
}tmp[MX], tmpArray[MX];

int n, SA[MX], Rank[MX];
int frequency[MX];
char s[MX];
void countingSort(int p)
{
    int maxi = max(n, 256);
    memset(frequency, 0, sizeof frequency);
    for(int i = 0; i < n; i++)
        frequency[tmp[i].r[p]+1]++;
    int sum = 0, prev;
    for(int i = 0; i <= maxi; i++){
        prev = frequency[i];
        frequency[i] = sum;
        sum += prev;
    }
    for(int i = 0; i < n; i++){
        tmpArray[frequency[tmp[i].r[p]+1]] = tmp[i];
        frequency[tmp[i].r[p]+1]++;
    }
    for(int i = 0; i < n; i++)
        tmp[i] = tmpArray[i];
}

void radixSort(){
    countingSort(1);
    countingSort(0);
}
int step;
void build_SuffixArray()
{
    int mini = (int)s[0];
    for(int i = 1;i<n;i++)
    {
        mini=min((int)s[i], mini);
    }
    for(int i = 0;i<n;i++)
    {
        Rank[i] = s[i]-mini;
    }
    step = 0;
    for(int siz=1;siz<n;siz<<=1){
        step++;
        for(int i = 0;i<n;i++){
            tmp[i].index = i;
            tmp[i].r[0] = Rank[i];
            tmp[i].r[1] = i+siz<n ? Rank[i+siz] : -1 ;
        }
        radixSort();
        //sort(tmp, tmp+n);
        int rnk = 0;
        Rank[tmp[0].index] = rnk;
        for(int i = 1;i<n;i++){
            if(tmp[i-1].r[0] != tmp[i].r[0] || tmp[i-1].r[1] != tmp[i].r[1])
                rnk++;
            Rank[tmp[i].index] = rnk;
        }
        if (rnk == n-1) break;
    }
    for(int i = 0;i<n;i++){
        SA[Rank[i]] = i;
    }
}
int p, q;
long long kasai()
{
    vector<int> lcp(n,0);
    long long sum = 0;
    for(int i=0, k=0; i<n; i++, k?k--:0){
        if(Rank[i]==n-1) { k=0; continue;}
        int j=SA[Rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[Rank[i]]=k;
        sum+=k;
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int test, cas=1;
    scanf("%d", &test);
    while(test--){
        scanf("%s", s);
        scanf("%d %d", &p, &q);
        n = strlen(s);
        build_SuffixArray();
        int sum = kasai();
        int ans = 1LL*n*(n+1)/2 - sum;
        printf("Case %d: %d\n", cas, ans); 
        cas++;
    }
    return 0;
}

