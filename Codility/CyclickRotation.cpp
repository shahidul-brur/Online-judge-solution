/**
 mistakes: 
   i)  swap pos to (pos+k)%n until pos != 0
   ii) swap pos to (pos+k)%n until n steps
   iii)  bug in reverse fn: loop to e-b/2, swapping v[i] with v[e-i] -> should be b+(e-b)/2, v[i] with v[b+e-i]
  
**/

vector<int> reverse(vector<int> &v, int b, int e) {
    for(int i = b; i<=b+(e-b)/2;i++) {
        swap(v[i], v[b+e-i]);
    }
    return v;
}
vector<int> solution(vector<int> &A, int K) {
    int n = (int) A.size();
    if (n == 0 || K%n==0) return A;
    K%=n;
    A = reverse(A, 0, n-1);
    A = reverse(A, 0, K-1);
    A = reverse(A, K, n-1);
    return A;
}
