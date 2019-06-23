#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e6 + 5;
int a[N], L[N], R[N], n;
long long res;
void cal(){
    for (int i = 1; i <= n; i++) {
        L[i] = i - 1;
        while (L[i] and a[L[i]] < a[i]) L[i] = L[L[i]];
    }
    for (int i = n; i >= 1; i--) {
        R[i] = i + 1;
        while (R[i] <= n and a[R[i]] <= a[i]) R[i] = R[R[i]];
    }
    for (int i = 1; i <= n; i++)
        res += 1LL * a[i] * 1LL * (i - L[i]) * 1LL * (R[i] - i);
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    cal();
    for (int i = 1; i <= n; i++) a[i] *= -1;
    cal();
    printf("%lld\n", res);
    return 0;
}