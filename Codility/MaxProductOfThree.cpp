#include <algorithm>
int solution(vector<int> &a) {
    sort(a.begin(), a.end());
    return max(a[0]*a[1]*a[n-1], a[n-1]*a[n-2]*a[n-3]);
}

// without sorting
int solution(vector<int> &a) {
    int mx_1 = -1001, mx_2=-1001, mx_3=-1001;
    int mn_1 = 1001, mn_2=1001;
    int n = a.size();
    for(int i=0;i<n;i++){
        if (a[i]>mx_1){
            mx_3 = mx_2;
            mx_2 = mx_1;
            mx_1 = a[i];
        }
        else if (a[i]>mx_2){
            mx_3 = mx_2;
            mx_2 = a[i];
        }
        else if (a[i]>mx_3){
            mx_3 = a[i];
        }

        if (a[i]<mn_1){
            mn_2 = mn_1;
            mn_1 = a[i];
        }
        else if (a[i]<mn_2){
            mn_2 = a[i];
        }
    }
    return max(mx_1*mx_2*mx_3, mn_1*mn_2*mx_1);
}
