// mistake: initializing i = 0
#include <cmath>
int solution(int N) {
    int rt = (int)sqrt(N);
    int factor = 0;
    for (int i = 1; i <= rt; i++) {
        if (N%i==0) {
            factor++;
            if (N/i != i) factor++;
        }
    }
    return factor;
}