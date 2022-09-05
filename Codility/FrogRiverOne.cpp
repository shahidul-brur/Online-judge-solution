/**
 mistake: returning i+1, using memset without including header
*/
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int visited[X+1], cnt = 0;
    for (int i=1;i<=X;i++) visited[i]=0;
    for (int i=0;i<(int)A.size();i++){
        if (A[i]<=X && A[i]>0 && visited[A[i]]==0){
            ++cnt;
            visited[A[i]] = 1;
            if (cnt==X) return i;
        }
    }
    return -1;
}
